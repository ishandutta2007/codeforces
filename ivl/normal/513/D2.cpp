#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

const int oo = 1000000000;
const int offset = 1 << 20;
class turnament{
      public:
      int T[offset * 2];
      turnament(){for (int i = 0; i < offset * 2; ++i) T[i] = 0;}
      int slo, shi, sval;
      void set(int id, int lo, int hi){
           if (lo > shi || hi < slo) return;
           if (lo == hi){T[id] = sval; return;}
           int mid = (lo + hi) / 2;
           set(id * 2, lo, mid);
           set(id * 2 + 1, mid + 1, hi);
           T[id] = max(T[id * 2], T[id * 2 + 1]);
      }
      void set(int pos, int val){
           slo = shi = pos, sval = val;
           set(1, 0, offset - 1);
      }
      int query(int id, int lo, int hi){
          if (lo > shi || hi < slo) return -oo;
          if (lo >= slo && hi <= shi) return T[id];
          int mid = (lo + hi) / 2;
          id *= 2;
          return max(query(id, lo, mid), query(id + 1, mid + 1, hi));
      }
      int query(int lo, int hi){
          slo = lo, shi = hi;
          return query(1, 0, offset - 1);
      }
} T;

void imp(){printf("IMPOSSIBLE\n"); exit(0);}

int n, c;
char in[1000005];
vector < int > l[1000005], r[1000005];
int llo[1000005], lhi[1000005], rlo[1000005], rhi[1000005];

vector < int > out;
void rek(int lo, int hi){
     if (lo > hi) return;
     rek(llo[lo], lhi[lo]);
     out.push_back(lo);
     rek(rlo[lo], hi);
}

int main(){
    scanf("%d%d", &n, &c);
    for (int i = 0; i < c; ++i){
        int a, b;
        scanf("%d%d%s", &a, &b, in);
        if (a >= b) imp();
        if (in[0] == 'L') l[a].push_back(b); else r[a].push_back(b);
    }
    for (int i = 1; i <= n; ++i) sort(l[i].begin(), l[i].end()), sort(r[i].begin(), r[i].end());
    for (int i = n; i >= 1; --i){
        llo[i] = i + 1;
        lhi[i] = i;
        if (l[i].size())
           lhi[i] = max(lhi[i], T.query(lhi[i], l[i].back()));
        if (r[i].size()) if (lhi[i] >= r[i][0]) imp();
        rlo[i] = lhi[i] + 1;
        rhi[i] = lhi[i];
        if (r[i].size())
           rhi[i] = max(rhi[i], T.query(rhi[i], r[i].back()));
        T.set(i, rhi[i]);
    }
    rek(1, n);
    for (int i = 0; i < out.size(); ++i) printf("%d ", out[i]); printf("\n");
    return 0;
}