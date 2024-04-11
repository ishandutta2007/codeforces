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

const int N=3e6+99;

int n,lazy[N];
ll ans;
vector<int> v[N];
pair<int,int> seg[N];
vector<pair<int,int> > last[N];

void shift(int,int,int);
 
pair<int,int> Min(pair<int,int> x,pair<int,int> y){
    if(y<x) swap(x,y);
    if(x.F == y.F) x.S+=y.S;
    return x;
}
void build(int id=1,int L=1,int R=n+1){
    seg[id].S=R-L;
    if(R<=L+1) return ;
    int mid=(L+R+1) >> 1;
    build(id*2+0, L, mid);
    build(id*2+1, mid, R);
}
void add(int id,int L,int R,int l,int r,int val){
    if(R<=l || r<=L) return ;
    if(l<=L && R<=r){
        lazy[id] += val;
        seg[id].F += val;
        return ;
    }
    int mid=(L+R+1)>>1;
    shift(id, L, R);
    add(id*2+0, L, mid, l, r, val);
    add(id*2+1, mid, R, l, r, val);
    seg[id]=Min(seg[id*2+0],seg[id*2+1]);
}
void shift(int id,int L,int R){
    int mid=(L+R+1) >> 1;
    add(id*2+0, L, mid, L, mid, lazy[id]);
    add(id*2+1, mid, R, mid, R, lazy[id]);
    lazy[id]=0;    
}

int main(){
    cin>>n;
    build();
    f(i,1,n+1){
        int x,t;
        gett(x);
        v[x].pb(i);
        f(i,0,last[x].size())
            add(1,1,n+1,last[x][i].F,last[x][i].S,-1);
        last[x].clear();
        
        if(2<v[x].size()) t=v[x][v[x].size()-3];
        else t=0;
        add(1,1,n+1,t+1,i+1,1);
        last[x].pb(mp(t+1,i+1));
        if(3<v[x].size()){
            add(1,1,n+1,1,v[x][v[x].size()-4]+1,1);
            last[x].pb(mp(1,v[x][v[x].size()-4]+1));
        }
        if(seg[1].F==0){
          //  cout<<i<<" : "<<seg[1].S<<" : "<<seg[1].S-(n-i)<<endl;
            ans+=seg[1].S-(n-i);
        }
    }
    cout<<ans;
}