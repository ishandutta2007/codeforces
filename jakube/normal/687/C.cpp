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
    cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    for (int idx = 0; idx < n;  idx++)
        cin >> c[idx];
    
    set<int> result;

    vector<vector<bool> > dp(251, vector<bool>(501, false)); 
    dp[0][0] = true;

    for (int d = 0; d < n; d++) {
        for (int a = 250; a >= 0; a--) {
            for (int b = 500; b >= 0; b--) {
                if (dp[a][b]) {
                    int e = c[d];
                    if (a + e <= 250)
                        dp[a+e][b] = true;
                    if (b + e <= 500)
                        dp[a][b+e] = true;
                }
            }
        }
    }
    
    for (int i = 0; i <= k; i++) {

        if (i <= 250 && k - i >= 0 && dp[i][k-i]) {
            result.insert(i);
            result.insert(k-i);
        }
    }

    cout << result.size() << endl;
    for (auto r : result)
        cout << r << " " ;
}