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
template <typename T, typename S>
void DBG(pair<T, S> p){if(debug)cout<<p.first<<" "<<p.second<<endl;}
template <typename T>
void DBG(vector<T> v){if(debug){for(T t:v)cout<<t<<"  ";cout<<endl;}}
template <typename T>
void DBG(T t){if(debug)cout<<t<<endl;}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    string p = "";
    string q = "";
    int balance = 0;
    for (char c : s)
    {
        if (c == '(')
        {
            balance++;
        }
        else
        {
            balance--;
        }

        if (balance < 0) {
            p += "(";
            balance++;
        }
    }
    FOR(i, balance)
        q += ")";


    int l = p.size() + q.size();
    if (m + l > n || (n - (m + l)) % 2)
    {
        cout << 0;
        return 0;
    }

    int a, b;
    a = p.size();
    b = q.size();

    int d = n - m;
    vector<vector<lint>> dp(d + 1, vector<lint>(d + 1, 0));
    //dp[count][open]
    dp[0][0] = 1;

    FORR(i, 1, d + 1)
    {
        FOR(j, i+1)
        {
            dp[i][j] = ((j > 0 ? dp[i-1][j-1] : 0) + (j < d - 1 ? dp[i-1][j+1] : 0)) % MOD;
        }
    }

    lint result = 0;
    FOR(i, d + 1)
    {
        FORR(j, a, i + 1)
        {
            if (j - a + b <= d)
                result = (result + dp[i][j] * dp[d - i][j - a + b]) % MOD;
        }
    }

    DBG(result);
}