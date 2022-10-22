/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define all(flg) flg.begin(), flg.end()
#define int long long
#define pb push_back
#define fi first
#define se second
#define eb emplace_back
#define ii pair<int, int>
#define vi vector<int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define ld long double
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 998244353;
const int maxN = 1000005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

const int INF=1e9+7,MAXN=3e6+10/*Min:2^20+10*/;
const ll BASE=3,MOD=998244353,INV=332748118;
#define vl vector<ll>
#define loopa(h) for(int i=0;i<h;i++)

ll fpm(ll num,ll coef){
    ll res=1; while(coef){
        if(coef&1)res=res*num%MOD;
        num=num*num%MOD;coef>>=1;
    }return res;
}int N,M,lim=1,lg;

vl NTT(vl a, vl bag,int type, int lim){
    loopa(lim)if(i<bag[i])swap(a[i],a[bag[i]]);
    for(int mid=1;mid<lim;mid<<=1){int len=mid<<1;
        ll Wn=fpm(type?BASE:INV,(MOD-1)/len);
        for(int j=0;j<lim;j+=len){
            ll w=1;
            for(int k=0;k<mid;k++){
                int x=a[j+k],y=w*a[j+k+mid]%MOD;
                a[j+k]=(x+y)%MOD;
                a[j+k+mid]=(x-y+MOD)%MOD;
                w=w*Wn%MOD;
            }
        }
    }
    return a;
}

vl mul(vl a, vl b){
    int N=a.size()-1,M=b.size()-1,lim=1,lg=0;
    vl res(N+M+1);
    while(lim<=N+M){lim<<=1;lg++;}
    vector<ll> bag(lim+1, 0);
    a.resize(lim,0);
    b.resize(lim,0);
    loopa(lim)bag[i]=(bag[i>>1]>>1)|((i&1)<<(lg-1));
    b=NTT(b,bag,1,lim);a=NTT(a,bag,1,lim);
    loopa(lim)a[i]=b[i]*a[i]%MOD;
    a=NTT(a,bag,0,lim);const ll perv=fpm(lim,MOD-2);
    loopa(N+M+1){res[i]=a[i]*perv%MOD;}
    return res;
}
#undef vl

/*
primes: 998244353 3
        1e9+7 5
        1e9+9 13
*/

int len;
vector<int> vc[maxN];
map<int, int> mp;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o >> n >> len; ++o;
    vi suck; suck.resize(n + 1);
    while(o--){
        cin >> x; suck[x] = 1;
    }
    vi sx = suck; reverse(all(sx));
    suck = mul(suck, sx);
    for1(i, 0, n) suck[i] = suck[i + n];
    suck.resize(n + 1);
    suck.resize(maxN);
    for1(i, len, maxN - 1) for(int j = i; j < maxN; j += i) vc[j].pb(i);
    cin >> o; for1(dumb, 1, o){
        cin >> x;
        // if(o > 1000){
        //     if(dumb == 1561){
        //         cout << x << " "; exit(0);
        //     }
        //     continue;
        // }
        if(mp.find(x / 2) != mp.end()){
            cout << mp[x / 2] << endl;
            continue;
        }
        x /= 2;
        int res = -1;
        for(int cc : vc[x]) if(suck[cc - len]) res = cc * 2;
        if(res == len * 2) res = -1;
        assert(!(x * 2 % res));
        cout << res << " ";
        mp[x] = res;
    }
    cout << endl;
}