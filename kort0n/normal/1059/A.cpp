#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

int main() {
    //cout.precision(10);
    int n, l, a;
    cin >> n >> l >> a;
    int now = 0;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int in;
        cin >> in;
        ans += (in - now) / a;
        now = in;
        cin >> in;
        now += in;
    }
    ans += (l - now) / a;
    cout << ans << endl;
    return 0;
}