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
    int n, m;
    cin >> m >> n;
    int ans = 0;
    while(true) {
        if(n % 2 != 0) break;
        if((n/2)%m != 0) break;
        n/=2;
        ans++;
    }
    while(true) {
        if(n % 3 != 0) break;
        if((n/3)%m != 0) break;
        n/=3;
        ans++;
    }
    if(n != m) ans = -1;
    cout << ans << endl;
    return 0;
}