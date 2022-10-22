#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
template<class T>
istream &operator >> (istream &in, vector<T> &v) {for (auto &i : v) {in >> i;}return in;}
template<class T>ostream &operator << (ostream &out, const vector<T> &v) {for (auto &i : v) {out << i << ' ';}return out;}
int MOD=1e9+7;
int main() {
    long long n,l,r,a3=1,a2=0,a1=0;
    cin >> n >> l >> r;
    a3 = r / 3 - (l - 1) / 3;
    a1 = (r + 2) / 3 - (l + 1) / 3;
    a2 = (r + 1) / 3 - l / 3;



    long long dp[n+1][3];
    dp[1][0]=a3;
    dp[1][1]=a1;
    dp[1][2]=a2;
    for(int i=2;i<=n;i++){
        dp[i][0]=(dp[i-1][0]*a3)%MOD+(dp[i-1][1]*a2)%MOD+(dp[i-1][2]*a1)%MOD;
        dp[i][0]%=MOD;
        //cout  << dp[i][0] << endl;
        dp[i][1]=(dp[i-1][0]*a1)%MOD+(dp[i-1][1]*a3)%MOD+(dp[i-1][2]*a2)%MOD;
        dp[i][1]%=MOD;
        //cout  << dp[i][1] << endl;
        dp[i][2]=(dp[i-1][0]*a2)%MOD+(dp[i-1][1]*a1)%MOD+(dp[i-1][2]*a3)%MOD;
        dp[i][2]%=MOD;
      //  cout  << dp[i][2] << endl;

    }
    cout << dp[n][0];


}