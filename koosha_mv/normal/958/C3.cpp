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
#define Add(x,y) x=(x+y)%p
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=5e5+99,K=103;
 
int n,k,p,dp[K][K],Fen[K][K],a[N];
 
void update(int x,int val,int s){ minm(dp[s][x],val); x++; while(x<=K)  { minm(Fen[s][x],val);  x+=(x&-x);  } }
 
int query(int x,int s) { int res=N; x++; while(x>0)  {  minm(res,Fen[s][x]);  x-=(x&-x);  } return res; } 
 
int main(){
    f(i,0,K) f(j,0,K) Fen[i][j]=N,dp[i][j]=N;
    update(0,0,0);
    cin>>n>>k>>p;
    f(io,1,n+1){
        int x;
        gett(a[io]);
        Add(a[io],a[io-1]);
        x=a[io];
        f_(i,k,1){
            update(x,query(x,i-1),i);
            update(x,query(p-1,i-1)+1,i);
        }
    }
    cout<<dp[k][a[n]]*p+a[n];
}