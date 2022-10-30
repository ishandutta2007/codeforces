#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define endl '\n'
#define all(var) var.begin(),var.end()
#define mp make_pair
#define gi(x) int(x-'a')
const ll MOD = 998244353;
ll proot = 0,rev2 = 0;
ll binpow(unsigned long long x,ll power){
    unsigned long long mult = x%MOD;
    x = 1;
    while(power){
        if (power&1)
            x = x*mult%MOD;
        mult = mult*mult%MOD;
        power = power>>1;
    }
    return x;
}
const int LOG = 30;
int WN[LOG];

void nnt(vector<int> &a,int flag){
    int sz = a.size();
    if (sz==1)
        return;
    vector<int> a1,a2;
    for(int i = 0;i<(sz>>1);++i){
        a1.push_back(a[i<<1]);
        a2.push_back(a[(i<<1)+1]);
    }
    int lg = 0;
    while((1<<lg)<sz)
        ++lg;
    nnt(a1,flag);
    nnt(a2,flag);
    ll w = 1,wn = WN[lg];
    if (flag)
        wn = binpow(wn,MOD-2);
    ll rev = rev2;
    for(int i = 0;i<(sz>>1);++i){
        a[i] = (a1[i]+ll(w)*a2[i])%MOD;
        a[i+(sz>>1)] = (a1[i]-ll(w)*a2[i])%MOD;
        if (a[i+(sz>>1)]<0)
            a[i+(sz>>1)]+=MOD;
        if (flag)
            a[i] = (ll(a[i])*rev)%MOD,a[i+(sz>>1)] = (ll(a[i+(sz>>1)])*rev)%MOD;
        w = (w*wn)%MOD;
    }
}
vector<int> poly_mult(vector<int> &a1,vector<int> &b1){
    int po = 1;
    while(po<a1.size()+b1.size())
        po = po<<1;
    a1.resize(po);
    b1.resize(po);
    nnt(a1,0);
    nnt(b1,0);
    for(int i = 0;i<po;++i)
        a1[i] = ll(a1[i])*b1[i]%MOD;
    nnt(a1,1);
    return a1;
}
const int N = 3e5+7;
int A[N],B[N];
ll fact[N],rev[N];
const int M = 6;
vector<int> CLK[M];
int C(int n,int k){
    if (n<0 || k<0 || n<k)
        return 0;
    return fact[n]*rev[k]%MOD*rev[n-k]%MOD;
}
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;++i)
        cin>>A[i];
    for(int i = 1;i<=m;++i)
        cin>>B[i];
    sort(A+1,A+1+n);
    sort(B+1,B+1+m);
    int single = 0,par = 0,flag = 0,ptr = 1;
    for(int i = 1;i<=m;++i){
        while(ptr<=n && A[ptr]<B[i]){
            if (A[ptr]==A[ptr-1]){
                if (!flag){
                    flag = 1;
                    --single;
                    ++par;
                }
            }
            else{
                flag = 0;
                ++single;
            }
            ++ptr;
        }
        vector<int> a(n+1),b(n+1);
        for(int i = 0;i<=n;++i){
            a[i] = C(par<<1,i);
            b[i] = ll(C(single,i))*binpow(2,i)%MOD;
        }
        CLK[i] = poly_mult(a,b);
    }
    int q;
    cin>>q;
    while(q--){
        int len;
        cin>>len;
        ll res = 0;
        for(int i = 1;i<=m;++i){
            int qnt = len-((B[i]+1)<<1);
            if (qnt<0)
                continue;
            qnt = qnt>>1;
            if (qnt<=n)
            res = (res+CLK[i][qnt])%MOD;
        }
        cout<<res<<endl;
    }

}
const int SZ = 102595;
bool vis[SZ];
signed main(){
    fact[0] = 1;
    for(int i = 1;i<N;++i)
        fact[i] = fact[i-1]*i%MOD;
    rev[N-1] = binpow(fact[N-1],MOD-2);
    for(int i = N-2;i>=0;--i)
        rev[i] = rev[i+1]*(i+1)%MOD;
    vector<int> primes;
    for(int pr = 2;pr*pr<SZ;++pr){
        if (vis[pr])
            continue;
        primes.push_back(pr);
        for(ll j = pr*pr;j<SZ;j+=pr)
            vis[j] = true;
    }
    vector<int> divs;
    for(int pr:primes){
        if ((MOD-1)%pr==0)
            divs.push_back(pr);
    }
    for(int root = 2;root<MOD;++root){
        int flag = 0;
        for(int to:divs) {
            ll val = binpow(root, (MOD - 1) / to);
            //cout << val << endl;
            if (binpow(root, (MOD - 1) / to) == 1) {
                flag = 1;
                break;
            }
        }
        if (!flag){
            proot = root;
            break;
        }
    }
    rev2 = binpow(2,MOD-2);
    assert(proot!=0);
    for(int i = 0;i<LOG;++i){
        WN[i] = binpow(proot,(MOD-1)/(1<<i));
    }
    //cout<<proot<<endl;
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //scanf("%d",&t);

    while(t--)
        solve();
}