#include <cstdio>
#include <set>
#define x first
#define y second
#include <vector>

using namespace std;

long long f(long long x){return x * (x + 1) / 2;}

class klasa{
      public:
      set < pair < int, int > > S;
      long long r;
      klasa(){
              r = 0;
              S.insert(make_pair(-100, -100));
              S.insert(make_pair(1000000, 1000000));
      }
      void add(int pos){
           set < pair < int, int > >::iterator it = S.lower_bound(make_pair(pos, pos));
           //printf("%d %d\n", it->x, it->y);
           pair < int, int > p = make_pair(pos, pos);
           vector < pair < int, int > > rem;
           if (it->x - 1 == pos){
              p.y = it->y;
              r -= f(it->y - it->x + 1);
              rem.push_back(*it);
           }
           --it;
           if (it->y + 1 == pos){
              p.x = it->x;
              r -= f(it->y - it->x + 1);
              rem.push_back(*it);
           }
           r += f(p.y - p.x + 1);
           S.insert(p);
           for (int i = 0; i < rem.size(); ++i) S.erase(rem[i]);
      }
      void remove(int pos){
           set < pair < int, int > >::iterator it = S.lower_bound(make_pair(pos, 1000000));
           //printf(" %d %d\n", it->x, it->y);
           --it;
           pair < int, int > p = *it;
           S.erase(it);
           r -= f(p.y - p.x + 1);
           if (p.x != pos){
              S.insert(make_pair(p.x, pos - 1));
              r += f(pos - p.x);
           }
           if (p.y != pos){
              S.insert(make_pair(pos + 1, p.y));
              r += f(p.y - pos);
           }
      }
      void print(){
           for (set < pair < int, int > >::iterator it = S.begin(); it != S.end(); ++it) printf("%d-%d, ", it->x, it->y);
           printf("\n");
      }
} calc[35];

int n, m;
int val[100005];

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i){
        int a;
        scanf("%d", &a);
        val[i + 1] = a;
        for (int j = 0; a; ++j, a >>= 1) if (a & 1) calc[j].add(i + 1);
    }
    for (int i = 0; i < m; ++i){
        int p, v;
        scanf("%d%d", &p, &v);
        int v2 = val[p];
        val[p] = v;
        for (int j = 0; v2 | v; ++j, (v >>= 1), (v2 >>= 1)){
            if ((v2 & 1) == 0 && (v & 1) == 1) calc[j].add(p);
            if ((v2 & 1) == 1 && (v & 1) == 0) calc[j].remove(p);
        }
        long long r = 0;
        for (int j = 0; j <= 32; ++j) r += (calc[j].r << j);
        //calc[0].print();
        printf("%I64d\n", r);
    }
    return 0;
}