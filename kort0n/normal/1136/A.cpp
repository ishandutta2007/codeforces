#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int ans = 0;
    int l[105];
    int r[105];
    for(int i = 1; i <= n; i++) cin >> l[i] >> r[i];
    int k;
    cin >> k;
    for(int i = 1; i <= n; i++) {
        if(r[i] >= k) ans++;
    }
    cout << ans << endl;
    return 0;
}