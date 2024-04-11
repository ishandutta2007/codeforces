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

const int N=6e5+99,inf=1e9+9;

int n,t,h[N],tree[2][N],ans[N];
vector<int> v[2];

void build(){
    f(i,n,2*n) tree[0][i]=tree[1][i]=h[i-n];
    f_(i,n-1,1){
        int u=i*2,v=i*2+1;
        tree[0][i]=min(tree[0][u],tree[0][v]);
        tree[1][i]=max(tree[1][u],tree[1][v]);
    }
}
int query(int l, int r,int s) {
    r++;
    int res=0;
    if(s==0) res=inf;
    if(r<l) return res;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1){
        if(s){ maxm(res,tree[s][l++]); }
        else minm(res,tree[s][l++]);
    }
    if (r&1){
        if(s){ maxm(res,tree[s][--r]); }
        else minm(res,tree[s][--r]);
    }
    }
    return res;
}

int main(){
    cin>>n;
    f(i,0,n) gett(h[i]);
    build();
    v[0].pb(0);
    v[1].pb(0);
    f(i,1,n){
        ans[i]=N;
        for(int j=sz(v[0])-1;0<=j && h[i]<query(v[0][j]+1,i-1,0);j--) minm(ans[i],ans[v[0][j]]);
        for(int j=sz(v[1])-1;0<=j && query(v[1][j]+1,i-1,1)<h[i];j--) minm(ans[i],ans[v[1][j]]);
        while(v[0].size() && h[i]<=h[lst(v[0])]) v[0].pop_back();
        while(v[1].size() && h[lst(v[1])]<=h[i]) v[1].pop_back();
        v[0].pb(i);
        v[1].pb(i);
        ans[i]++;
    }
    cout<<ans[n-1];
}