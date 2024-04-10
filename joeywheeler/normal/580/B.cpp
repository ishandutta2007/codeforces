#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, d;
pair<int,int> f[100005];
typedef long long ll;

int main() {
    scanf("%d%d", &n, &d);
    FO(i,0,n) {
        scanf("%d%d", &f[i].first, &f[i].second);
    }
    sort(f,f+n);
    int r = 0;
    ll sum = 0, res = 0;
    FO(i,0,n) {
        while (r < n && f[i].first+d>f[r].first) {
            sum += f[r].second;
            r++;
        }
        res = max(res,sum);
        sum -= f[i].second;
    }
    printf("%lld\n", res);
}