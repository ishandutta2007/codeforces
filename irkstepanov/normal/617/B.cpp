#include <iostream>
#include <vector>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

int main()
{

    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }

    vector<ll> dp(n + 1);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        int cnt = v[i];
        int pos = i - 1;
        while (!cnt && pos) {
            cnt += v[pos];
            --pos;
        }
        if (!cnt) {
            continue;
        }
        while (pos) {
            dp[i] += dp[pos];
            if (v[pos]) {
                break;
            }
            --pos;
        }
        //cout << i << " " << cnt << " " << pos << "\n";
        if (!pos) {
            dp[i] += dp[0];
        }
        //cout << dp[i] << "\n";
    }

    cout << dp[n] << "\n";

}