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
#define Add(a,b) a=(a+b)%mod;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=4005,K=805,inf=1e9;
 
int n,k,a[N],g[N][N],dp[K][N],cost[N][N];
 
void find_costs(){
    f(i,1,n+1){
        int sum=0;
        f_(j,i,1){
            a[j]+=g[i][j];
            sum+=a[j];
            cost[j][i]=sum;
        }
    }
}
void calc(int l,int r,int L,int R,int k){
    int mid=(l+r)>>1,p;
    if(r<l) return;
    dp[k][mid]=inf;
    f(i,L,R+1){
        if(cost[i+1][mid]+dp[k-1][i]<dp[k][mid])
            dp[k][mid]=cost[i+1][mid]+dp[k-1][i],p=i;
    }
   // cout<<mid<<" "<<dp[k][mid]<<endl;
    if(l==r) return ;
    calc(l,mid-1,L,p,k);
    calc(mid+1,r,p,R,k);
}
 
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    f(i,1,N) dp[0][i]=inf;
    f(i,1,N) f(j,1,N) cost[i][j]=inf;
    cin>>n>>k;
    f(i,1,n+1)
        f(j,1,n+1){
            char c;
            cin>>c;
            g[i][j]=c-'0';
        }
    find_costs();
    f(i,1,k+1){
      //  cout<<i<<" : "<<endl;
        calc(1,n,0,n,i);
    }
    cout<<dp[k][n];
}