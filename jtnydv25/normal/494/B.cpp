#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pb push_back
#define ll long long     
const int N = 100005;
const int base = 541, mod  = 1e9 + 7;
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
inline int powr(int a, ll b){
    int x = 1 % mod;
    while(b){
        if(b & 1) x = mul(x, a);
        a = mul(a, a);
        b >>= 1;
    }
    return x;
}
inline int inv(int a){ return powr(a, mod - 2);}
int H[N], pw[N], dp[N], dp2[N], dp3[N];
vector<int> R;
int getHash(int i, int j){
    return sub(H[j], mul(pw[j - i + 1], H[i - 1]));
}

int main(){
    pw[0] = 1;
    for(int i = 1; i < N; i++) pw[i] = mul(pw[i - 1], base);
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    for(int i = 1; i <= n; i++) H[i] = add(mul(H[i - 1], base), s[i - 1] - 'a' + 1);
    int ht = 0;
    for(int i = 1; i <= m; i++) ht = add(mul(ht, base), t[i - 1] - 'a' + 1);
    for(int i = 1; i + m - 1 <= n; i++){
        if(getHash(i, i + m - 1) == ht) R.pb(i + m - 1);
    }
    for(int i = 1; i <= n; i++){
        int ind = upper_bound(R.begin(), R.end(), i) - R.begin() - 1;
        if(ind >= 0){
            int j = R[ind] - m + 1;
            dp[i] = add(j, sub(mul(dp2[j - 1], j), dp3[j - 1]));
        }
        dp2[i] = add(dp2[i - 1], dp[i]);
        dp3[i] = add(dp3[i - 1], mul(i, dp[i]));   
    }
    printf("%d\n", dp2[n]);
}