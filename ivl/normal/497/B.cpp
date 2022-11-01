#include <cstdio>
#include <vector>
#define x first
#define y second
#include <algorithm>

using namespace std;

int n;
int a[100005];
int pr[100005];

int x(int a, int b){return pr[b] - pr[a - 1];}
int y(int a, int b){return b - a + 1 - pr[b] + pr[a - 1];}

int main(){
    scanf("%d", &n);
    pr[0] = 0;
    for (int i = 1; i <= n; ++i){
        scanf("%d", a + i); --a[i];
        pr[i] = a[i] + pr[i - 1];
    }
    pr[n + 1] = pr[n];
    vector < pair < int, int > > sol;
    for (int t = 1; t <= n; ++t){
        int xx = 0, yy = 0;
        bool nema = false;
        bool last;
        int curr = 1;
        while (curr <= n){
              if (x(curr, n) < t && y(curr, n) < t){nema = true; break;}
              int lo = curr, hi = n, mid = (lo + hi) / 2;
              while (lo != hi){
                    if (x(curr, mid) >= t || y(curr, mid) >= t) hi = mid;
                    else lo = mid + 1;
                    mid = (lo + hi) / 2;
              }
              if (x(curr, mid) == t){++xx; last = false;} else {++yy; last = true;}
              curr = mid + 1;
        }
        if (nema) continue;
        if (xx == yy) continue;
        if (xx > yy && last) continue;
        if (xx < yy && !last) continue;
        sol.push_back(make_pair(max(xx, yy), t));
    }
    sort(sol.begin(), sol.end());
    printf("%d\n", sol.size());
    for (int i = 0; i < sol.size(); ++i) printf("%d %d\n", sol[i].x, sol[i].y);
    return 0;
}