#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int p1 = 41;
const int p2 = 101;

const int MOD1 = 1000000007;
const int MOD2 = 998244353;

int mul(ll a, ll b, int mod){
    a %= mod;
    b %= mod;
    return (a*b)%mod;
}

int add(ll a, ll b, int mod){
    a %= mod;
    b %= mod;
    return (a+b)%mod;
}

ll pw(ll a, ll b, int mod){
    if(b == 1) return a;
    ll res = pw(a, b/2, mod);
    res = mul(res, res, mod);
    if(b%2) res = mul(res, a, mod);
    return res;
}

void solve(){
    string S;
    cin >> S;
    int n = S.size();

    /*a[0] = ra[0] = (s[0]-'a'+1);
    for(int i=1; i<n; i++){
        a[i] = add(a[i-1], mul(pw1[i], A[I]), MOD1);
        ra[i] = add(mul(ra[i-1], p, MOD1), s[i]-'a'+1, MOD1);
    }
    b[n-1] = rb[n-1] = s[n-1]-'a'+1;
    for(int i=n-2; i>=0; i--){
        b[i] = add(b[i+1])
        rb[i] = add()
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){

        }
    }*/
    int d1 = 0, d2;
    string pref = "", suf = "";
    for(int i=0; i<n-i-1; i++){
        if(S[i] != S[n-i-1]) break;
        pref += S[i];
        suf += S[n-i-1];
    }
    reverse(suf.begin(), suf.end());
    n -= 2*pref.size();
    string s = "";
    for(int i=0; i<n; i++){
        s += S[pref.size()+i];
    }
    if(n <= 1){
        cout << pref << s << suf << "\n";
        return;
    }
    int pp1 = 1;
    int pp2 = 1;
    int hes1 = 0, rhes1 = 0, hes2 = 0, rhes2 = 0;
    int mx1 = -1, mx2 = -1;
    for(int i=0; i<n; i++){
        hes1 = add(mul(hes1, p1, MOD1), s[i]-'a'+1, MOD1);
        rhes1 = add(rhes1, mul(pp1, s[i]-'a'+1, MOD1), MOD1);
        hes2 = add(mul(hes2, p2, MOD2), s[i]-'a'+1, MOD2);
        rhes2 = add(rhes2, mul(pp2, s[i]-'a'+1, MOD2), MOD2);
        pp1 = mul(pp1, p1, MOD1);
        pp2 = mul(pp2, p2, MOD2);
        if(hes1 == rhes1 && hes2 == rhes2){
            mx1 = max(mx1, i);
        }
    }
    hes1 = 0, rhes1 = 0, hes2 = 0, rhes2 = 0;
    pp1 = 1, pp2 = 1;
    for(int i=n-1; i>=0; i--){
        hes1 = add(mul(hes1, p1, MOD1), s[i]-'a'+1, MOD1);
        rhes1 = add(rhes1, mul(pp1, s[i]-'a'+1, MOD1), MOD1);
        hes2 = add(mul(hes2, p2, MOD2), s[i]-'a'+1, MOD2);
        rhes2 = add(rhes2, mul(pp2, s[i]-'a'+1, MOD2), MOD2);
        pp1 = mul(pp1, p1, MOD1);
        pp2 = mul(pp2, p2, MOD2);
        if(hes1 == rhes1 && hes2 == rhes2){
            mx2 = max(mx2, n-i-1);
        }
    }
    string rr = "";
    if(mx1 > mx2){
        for(int j=0; j<=mx1; j++) rr += s[j];
        cout << pref << rr << suf << "\n";
        return;
    }
    else{
        for(int i=n-1; i>=n-mx2-1; i--){
            rr += s[i];
        }
        reverse(rr.begin(), rr.end());
        cout << pref << rr << suf << "\n";
        return;
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}