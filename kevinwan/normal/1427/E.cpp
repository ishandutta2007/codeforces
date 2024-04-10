#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
typedef vector<int> vi;
typedef vector<ll> vl;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=52+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
const ll half=(mod+1)/2;
const double PI=acos(-1);
vector<string>v;
void ad(ll a,ll b){v.push_back(to_string(a)+" + "+to_string(b));}
void xo(ll a,ll b){v.push_back(to_string(a)+" ^ "+to_string(b));}
void solve(ll x){
    ll lp=1LL<<__builtin_ctz(x);
    if(x==lp)return;
    int a=0,b=0;
    for(int i=0;i<20;i++)if((x>>i)&1){
            b=a;
            a=i;
        }
    int d=a-b;
    for(int i=0;i<d;i++)ad(x<<i,x<<i);
    ll xd=x<<d;
    xo(xd,x);
    ll cs=(x<<d)^x;
    ad(cs,x),ad(cs,x<<1),ad(xd,x),ad(xd,x<<1);
    ll csp=cs+x,cspp=cs+x*2;
    ll xdp=xd+x,xdpp=xd+x*2;
    xo(csp,xd);
    xo(csp,xdp);
    xo(cspp,xd);
    xo(cspp,xdp);
    xo(cspp,xdpp);
    ll nx=min({csp^xd,csp^xdp,cspp^xd,cspp^xdp,cspp^xdpp});
    solve(nx);
    ll pp=1LL<<__builtin_ctz(nx);
    if(pp==lp)return;
    for(ll i=pp;x>i;i<<=1){
        if(x&i) {
            xo(x, i);
            x ^= i;
        }
        ad(i,i);
    }
    if(x!=lp)solve(x);
}
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#else
#endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    ll x;
    cin>>x;
    solve(x);
    printf("%d\n",v.size());
    for(string s:v)printf("%s\n",s.c_str());
}