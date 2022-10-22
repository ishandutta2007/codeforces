#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-9;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef __int128 lll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const int mn=3e5+10;
mt19937 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
auto begin_time=std::chrono::high_resolution_clock::now();
const ll mod=998244353;
int laz[mn*4];
void prop(int x){
    if(laz[x]==-1)return;
    if(x*2+1<mn*4){
        laz[x*2]=laz[x*2+1]=laz[x];
    }
    laz[x]=-1;
}
#define mid ((l+r)>>1)
void writ(int x,int l,int r,int a,int b,int c){
    //cerr<<x<<" "<<l<<" "<<r<<" "<<a<<" "<<b<<endl;
    if(l==a&&r==b)laz[x]=c;
    else{
        prop(x);
        if(b<=mid)writ(x*2,l,mid,a,b,c);
        else if(a>mid)writ(x*2+1,mid+1,r,a,b,c);
        else writ(x*2,l,mid,a,mid,c),writ(x*2+1,mid+1,r,mid+1,b,c);
    }
}
int red(int x,int l,int r,int a){
    if(l==r||laz[x]!=-1)return laz[x];
    else if(a<=mid)return red(x*2,l,mid,a);
    else return red(x*2+1,mid+1,r,a);
}
vi g[mn],h[mn];
int o[mn],s[mn],ct;
void dfsh(int x){
    o[x]=ct++,s[x]=1;
    for(int y:h[x])dfsh(y),s[x]+=s[y];
}
int ans,cur;
void dfsg(int x){
    int occ = red(1,0,ct-1,o[x]);
    if(!occ)++cur;
    else writ(1,0,ct-1,o[occ],o[occ]+s[occ]-1,0); 
    writ(1,0,ct-1,o[x],o[x]+s[x]-1,x);
    ans=max(ans,cur);
    for(int y:g[x])dfsg(y);
    writ(1,0,ct-1,o[x],o[x]+s[x]-1,0);
    if(occ) writ(1,0,ct-1,o[occ],o[occ]+s[occ]-1,occ);
    else --cur;
}

void solve(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)g[i].clear(),h[i].clear();
    for(int i=1;i<=n*4;i++)laz[i]=-1;
    laz[1]=0;
    for(int i=2;i<=n;i++){
        int x;
        scanf("%d",&x);
        g[x].push_back(i);
    }
    for(int i=2;i<=n;i++){
        int x;
        scanf("%d",&x);
        h[x].push_back(i);
    }
    ct=0;
    dfsh(1);
    assert(ct==n&&s[1]==n);
    ans=cur=0;
    dfsg(1);
    printf("%d\n",ans);
}
int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        solve();
    }
}