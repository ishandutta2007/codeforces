#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
const lll ONE=1;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=5e5+10,mv=1e3+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
int a[mn],b[mn],v[mn];
int p[mv],s[mv],rk[mv];
vector<int>seg[mn*4];
int f(int x){
    if(x==p[x])return x;
    int r=f(p[x]);
    s[x]^=s[p[x]];
    return p[x]=r;
}
void mer(int a,int b,int v){
    a=f(a),b=f(b);
    if(a==b)return;
    if(rk[a]<rk[b])swap(a,b);
    s[b]=v;
    p[b]=a;
    rk[a]=(rk[a]==rk[b]?(rk[a]+1):rk[a]);
}
#define mid ((l+r)>>1)
void init(int x,int l,int r){
    vector<int>o(r-l+1);
    iota(o.begin(),o.end(),l);
    sort(o.begin(),o.end(),[](int a,int b){return v[a]>v[b];});
    for(int i:o){
        seg[x].push_back(i);
        int aa=f(a[i]),bb=f(b[i]);
        if(aa==bb){
            if(s[a[i]]==s[b[i]])break;
            else seg[x].pop_back();
        }
        else{
            mer(aa,bb,s[a[i]]^s[b[i]]^1);
        }
    }
    for(int i:o)p[a[i]]=a[i],p[b[i]]=b[i],s[a[i]]=s[b[i]]=rk[a[i]]=rk[b[i]]=0;
    if(l!=r){
        init(x*2,l,mid);
        init(x*2+1,mid+1,r);
    }
}
vector<int>e;
void qu(int x,int l,int r,int a,int b){
    if(l==a&&r==b)for(int i:seg[x])e.push_back(i);
    else if(b<=mid)qu(x*2,l,mid,a,b);
    else if(a>mid)qu(x*2+1,mid+1,r,a,b);
    else qu(x*2,l,mid,a,mid),qu(x*2+1,mid+1,r,mid+1,b);
}
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++)cin>>a[i]>>b[i]>>v[i];
    iota(p,p+mv,0);
    init(1,1,m);
    while(q--){
        int l,r;
        cin>>l>>r;
        e.clear();
        iota(p,p+mv,0);
        memset(s,0,sizeof(s));
        memset(rk,0,sizeof(rk));
        qu(1,1,m,l,r);
        sort(e.begin(),e.end(),[](int a,int b){return v[a]>v[b];});
        int ans=-1;
        for(int i:e){
            int aa=f(a[i]),bb=f(b[i]);
            if(aa==bb){
                if(s[a[i]]==s[b[i]]){
                    ans=v[i];
                    break;
                }
            }
            else{
                mer(aa,bb,s[a[i]]^s[b[i]]^1);
            }
        }
        printf("%d\n",ans);
    }
}