#include <cstdio>
#include <vector>
#include <algorithm>

#define FO(i,a,b) for (int i = a; i < b; i++)
#define sz(v) int(v.size())

using namespace std;

vector<int> p;
int n, a[105], l[105];
int dp[305][105];

int gp(int x) {return lower_bound(p.begin(),p.end(),x)-p.begin();}

int main() {
    scanf("%d", &n);
    FO(i,0,n) scanf("%d %d", a+i, l+i);
    FO(i,0,n) FO(j,0,i) if (a[i] < a[j]) {
        swap(a[i],a[j]); swap(l[i],l[j]);
    }
    FO(i,0,n) p.push_back(a[i]-l[i]), p.push_back(a[i]+l[i]), p.push_back(a[i]);
    sort(p.begin(),p.end()); p.resize(unique(p.begin(),p.end())-p.begin());
    for (int xi = sz(p)-2; xi >= 0; xi--) {
        int x = p[xi];
        for (int i = n-1; i >= 0; i--) {
            if (a[i] <= x) {
                int nx = max(x, a[i]+l[i]);
                dp[xi][i] = max(dp[xi][i], dp[gp(nx)][i+1] + nx-x);
            } else {
                dp[xi][i] = dp[xi+1][i];
                int mr = x;
                FO(j,i,n) {
                    if (a[j]-l[j] <= x) {
                        int nx = max(mr, a[j]);
                        dp[xi][i] = max(dp[xi][i], dp[gp(nx)][j+1] + nx-x);
                    }
                    mr = max(mr, a[j]+l[j]);
                }
            }
        }
    }
    printf("%d\n", dp[0][0]);
}