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

    int n;
    cin >> n;

    map<int, int> m;
    FOR(i, 1e5+1)
        m[i] = 0;

    FOR(i, n) {
        int tmp;
        cin >> tmp;
        m[tmp]++;
    }

    lint total = 0;


    vector<vector<lint>> dp(100001, vector<lint>(2, 0));
    FORR(i, 1, 100001)
    {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = dp[i-1][0] + (lint)i*m[i];
    }

    cout << max(dp[1e5][0], dp[1e5][1]);
}