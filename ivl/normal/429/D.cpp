#include <cstdio>
#include <set>
#include <algorithm>
#include <vector>
#define x first
#define y second
#include <cmath>

using namespace std;

long long sq(long long x){return x * x;}

int n;
int a[100005];

vector < pair < int, int > > tocke;

long long solve(){ // sweep
     sort(tocke.begin(), tocke.end());
     
     set < pair < int, int > > S1;
     set < pair < int, int > > S2;
     
     long long r = 1000000000000000000LL;
     long long rt = sqrt(r) + 1;
     
     for (int i = 0; i < tocke.size(); ++i){
         
         while (true){
               if (S1.empty()) break;
               if (sq(S1.begin()->x - tocke[i].x) < r) break;
               S2.erase(make_pair(S1.begin()->y, S1.begin()->x));
               S1.erase(S1.begin());
         }
         
         set < pair < int, int > > ::iterator it1, it2;
         it1 = S2.lower_bound(make_pair(tocke[i].y - rt - 5, 0));
         it2 = S2.upper_bound(make_pair(tocke[i].y + rt + 5, 0));
         while (it1 != it2){
               int x = it1->y;
               int y = it1->x;
               long long r2 = sq(x - tocke[i].x) + sq(y - tocke[i].y);
               if (r2 < r) r = r2;
               ++it1;
         }
         
         S1.insert(tocke[i]);
         S2.insert(make_pair(tocke[i].y, tocke[i].x));
         
         rt = sqrt(r) + 1;
     }
     
     return r;
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    pair < int, int > t;
    t.x = t.y = 0;
    for (int i = 0; i < n; ++i){
        ++t.x;
        t.y += a[i];
        tocke.push_back(t);
    }
    printf("%I64d\n", solve());
    return 0;
}