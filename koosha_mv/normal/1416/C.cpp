#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e6+99;

int n,x,a[N];
ll mv[2],ans;
vector<int> e;
vector<vector<int> > v[32];

void solve(vector<int> V,int lg){
    if(lg<0) return ;
    if(!V.size()) return ;
    int p=0;
    ll res0=0,res1=0;
    vector<int> v0,v1;
    f(i,0,V.size()){
        if(a[V[i]]&(1<<lg)) v1.pb(V[i]);
        else v0.pb(V[i]);
    }
    f(i,0,v0.size()){
        while(p<v1.size() && v1[p]<v0[i]) p++;
        res0+=p;
    }
    res1=1ll*sz(v1)*sz(v0)-res0;
    mv[0]+=res0;
    mv[1]+=res1;
    if(lg) v[lg-1].pb(v0),v[lg-1].pb(v1);
}

int main(){
    cin>>n;
    f(i,0,n){ cin>>a[i]; e.pb(i); }
    v[30].pb(e);
    f_(i,30,0){
        f(j,0,v[i].size())
            solve(v[i][j],i);
        if(mv[0]<=mv[1]) ans+=mv[0];
        else ans+=mv[1],x|=(1<<i);
        mv[0]=mv[1]=0;
    }
    cout<<ans<<" "<<x;
}