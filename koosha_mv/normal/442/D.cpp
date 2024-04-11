#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define All(x) x.begin(),x.end()
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e6+99;

int n,dp[N],par[N];
pair<int,int> mx[N];

int calc(int x){
    if(x==1) return mx[x].F;
	return mx[x].F+mx[x].S;
}
void update(int x){
    if(calc(x)==dp[x]) return ;
    dp[x]=calc(x);
    if(dp[x]==mx[par[x]].F) mx[par[x]].S=1;
    if(mx[par[x]].F<dp[x]) mx[par[x]]=mp(dp[x],0);
    if(x!=1) update(par[x]);
}

int main(){
    cin>>n;
    f(i,2,n+2){
        int u;
        gett(u);
        dp[i]=1;
        par[i]=u;
        if(mx[par[i]].F==1) mx[par[i]].S=1;
        if(mx[par[i]].F==0) mx[par[i]]=mp(1,0);
        update(par[i]);
        cout<<dp[1]<<'\n';
    }
}