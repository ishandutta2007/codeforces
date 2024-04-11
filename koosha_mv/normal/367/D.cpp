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

const int N=1e5+9;

int n,m,d,ans=22,col[N],mark[22],dp[(1<<20)+10];
int mask;

void Add(int x){
    x=col[x];
    mark[x]++;
    mask|=(1<<x);
}
void del(int x){
    x=col[x];
    mark[x]--;
    if(mark[x]==0) mask-=(1<<x);
}
void check(int mask){
    f(i,0,m)
        dp[mask]|=dp[mask|(1<<i)];
    if(!dp[mask])
        minm(ans,__builtin_popcount(mask));
}

int main(){
    cin>>n>>m>>d;
    f(i,0,m){
        int sz;
        cin>>sz;
        f(j,0,sz){
            int x;
            gett(x);
            col[x]=i;
        }
    }
    int mv=(1<<m)-1;
    f(i,1,d+1) Add(i);
    dp[mv-mask]=1;
    f(i,d+1,n+1){
        Add(i);
        del(i-d);
        dp[mv-mask]=1;
    }
    f_(i,mv,1)
        check(i);
    cout<<ans;
}