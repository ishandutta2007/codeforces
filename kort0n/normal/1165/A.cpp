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
    int n, x, y;
    cin >> n >> x >> y;
    int ans = 0;
    string S;
    cin >> S;
    reverse(S.begin(), S.end());
    for(int i = x - 1; i >= 0; i--) {
        if((i == y) ^ (S[i] == '1')) {
            ans++;
            //cerr << i << endl;
        }
    }
    cout << ans << endl;
    return 0;
}