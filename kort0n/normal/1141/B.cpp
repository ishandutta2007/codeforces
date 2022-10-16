#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int n;
int a[400500];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i+n] = a[i];
    }
    a[2*n+1] = 0;
    int ans = 0;
    int now = 0;
    for(int i = 1; i <= 2 * n + 1; i++) {
        if(a[i] == 1) now++;
        else now = 0;
        ans = max(ans, now);
    }
    cout << ans << endl;
    return 0;
}