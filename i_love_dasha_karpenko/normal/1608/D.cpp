#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define all(var) var.begin(), var.end()
#define mp make_pair
#define gp(x,y) ((x-1)*m+y-1)
#define gi(ch) (ch=='W'?0:1)
const int MOD = 998244353;
const int N = 1e5+7;
ll fact[N],rev[N];
ll binpow(ll x,int power){
    ll mult = x%MOD;
    x = 1;
    while(power){
        if (power&1)
            x = x*mult%MOD;
        mult = mult*mult%MOD;
        power = power>>1;
    }
    return x;
}
ll C(int n,int k){
    if (n<0 || k<0 || n<k)
        return 0;
    return fact[n]*rev[n-k]%MOD*rev[k]%MOD;
}
void solve(){
    int n;
    cin>>n;
    int fbeg = 0,fen = 0;
    int beg[] = {0,0},en[] = {0,0};
    int flag = 0;
    int cb = -1,ce = -1,fb = 0,fe = 0,full = 0;
    int cnt1 = 0;
    for(int i = 1;i<=n;++i){
        string s;
        cin>>s;
        if (s[0]!='?')
            beg[gi(s[0])]++;
        else ++fbeg;
        if (s[1]!='?')
            en[gi(s[1])]++;
        else ++fen;
        if (s[0]==s[1] && s[0]!='?')
            flag = 1;
        if (s[0]!='?' && cb==-1)
            cb = gi(s[0]);
        if (s[0]!='?' && cb!=gi(s[0]))
            fb = 1;
        if (s[1]!='?' && ce==-1)
            ce = gi(s[1]);
        if (s[1]!='?' && ce!=gi(s[1]))
            fe = 1;
        if (s[0]==s[1] && s[0]=='?')
            full++;
        if (s[0]=='?' && s[1]=='B')
            ++cnt1;
    }
    ll res = 0;
    for(int w_beg = 0;w_beg<=fbeg;++w_beg){
        int b_beg = fbeg-w_beg;
        int w_end = beg[1]+b_beg-en[0];
        int b_end = beg[0]+w_beg-en[1];
        if (b_beg<0 || w_end+b_end!=fen || w_end<0 || b_end<0)
            continue;
        if (flag)
            res += C(fbeg,w_beg)*C(fen,w_end)%MOD;
        else{
            res += C(fbeg,w_beg)*C(fen,w_end)%MOD;
            if (max(w_beg+beg[0],b_beg+beg[1])!=n){
                int cp = w_beg-cnt1;
                res-=C(full,cp);
            }
        }
        if (res>=MOD)
            res-=MOD;
        if (res<0)
            res+=MOD;
    }
    cout<<res<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    fact[0] = 1;
    for(int i = 1;i<N;++i)
        fact[i] = fact[i-1]*i%MOD;
    rev[N-1] = binpow(fact[N-1],MOD-2);
    for(int i = N-2;i>=0;--i){
        rev[i] = rev[i+1]*(i+1)%MOD;
    }
    int t = 1;
   // cin>>t;
    while(t--)
        solve();
}