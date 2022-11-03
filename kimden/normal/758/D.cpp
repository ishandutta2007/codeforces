#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using ld = long double;

const ll mod = 1000000007;
ll a[101][101];

int main() {
    ios_base::sync_with_stdio(false);
    string sbase;
    ll base;
    ll dp[100];
    ll minsz[100];
    ll move[100];
    cin >> sbase;
    stringstream strstr(sbase);
    strstr >> base;
    string s;
    cin >> s;
    if(base <= 10){
        ll ans = 0;
        for(int i = 0; i < s.length(); i++){
            ans *= base;
            ans += (s[i] - '0');
        }
        cout << ans << endl;
        return 0;
    }
    dp[0] = 0;
    minsz[0] = 0;
    move[0] = 0;
    ll tmp;
    string tmp2;
    for(int i = 1; i <= s.length(); i++){
//        dp[i] = s[s.length() - i] - '0';
//        minsz[i] = minsz[i - 1] + 1;
//        move[i] = 1;
        dp[i] = mod * 21;
        minsz[i] = mod * 21;
        move[i] = -1;

        for(int j = max(0, i - (int)sbase.length()); j < i; j++){
            tmp2 = s.substr(s.length() - i, i - j);
            if(((tmp2.length() == sbase.length()) && tmp2 >= sbase) || (tmp2[0] == '0' && tmp2.length() > 1)){
                continue;
            }
            stringstream str2(tmp2);
            str2 >> tmp;
            if(minsz[j] + 1 < minsz[i] || (minsz[j] + 1 == minsz[i] && dp[i] > tmp)){
                dp[i] = tmp;
                minsz[i] = minsz[j] + 1;
                move[i] = i - j;
            }
        }
    }
    ll ans = 0;
    for(int i = (int)s.length(); i > 0; i -= move[i]){
        ans *= base;
        ans += dp[i];
//        cerr << move[i] << " ";
    }
//    cerr << endl;
    cout << ans << endl;
    return 0;
}