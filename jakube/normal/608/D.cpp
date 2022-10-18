#include <bits/stdc++.h>

using namespace std;

#define ALL(v) v.begin(),v.end()
#define FOR(I, N) for (int I = 0; I < (N); ++I)
#define FORR(I, A, B) for (int I = (A); I < (B); ++I)

const double EPS = 1e-4;
const long double PI = acos((long double)-1.0);
const long long int MOD = 1e9 + 7;

typedef long long int lint;
typedef long double ld;
lint powmod(lint a,lint b, lint mod) {lint res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

const int debug = 1;
template <typename T>
void DBG(vector<T> v){if(debug){for(T t:v)cout<<t<<"  ";cout<<endl;}}
template <typename T>
void DBG(T t){if(debug)cout<<t<<endl;}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vector<int> v(n);
    FOR(i,n)cin>>v[i];

    vector<vector<int>> dp(n, vector<int>(n, 0));

    FOR(i, n)
        dp[i][i] = 1;

    FORR(length, 2, n + 1)
    {
        FOR(pos, n - length + 1)
        {
            // 1...
            int best = 1 + dp[pos + 1][pos + length - 1];

            // 11...
            if (v[pos] == v[pos + 1])
            {
                int tmp = 1;
                if (length > 2)
                    tmp += dp[pos + 2][pos + length - 1];

                best = min(best, tmp);
            }

            // 1...1 ...
            FORR(k, pos + 2, pos + length)
            {
                if (v[pos] == v[k])
                {
                    int tmp = dp[pos + 1][k - 1];
                    if (k < pos + length - 1)
                        tmp += dp[k + 1][pos + length - 1];

                    best = min(best, tmp);
                }
            }

            dp[pos][pos + length - 1] = best;
        }
    }

    cout << dp[0][n-1];
}