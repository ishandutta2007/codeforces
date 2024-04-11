#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define is_bit(x,y) (0<(x&(1ll<<y)))
#define get(x) scanf("%I64d",&x);
#define All(x) x.begin(),x.end()
#define gett(x) scanf("%d",&x);a
#define Add(x,y) x=(x+y)%mod;
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=205,Lg=62,S=2;

int n,k,ans,dp[2][N][N]; 
string s,t;

void case1(){
    int num=0;
    f(i,0,n)
        num+=(s[i]==t[0]);
    num=min(n,num+k);
    cout<<num*(num-1)/2;
    exit(0);
}
void calc(int x,int k,int num){
    int src=x%2;
    dp[src][k][num]=dp[1-src][k][num];
    if((k || (t[0]==s[x])) && num)
        maxm(dp[src][k][num],dp[1-src][k-1+(t[0]==s[x])][num-1]);
    if(k || t[1]==s[x]){
    //    if(x==2 && k==1 && num==1) cout<<1-src<<" "<<k-1+(t[1]==s[x])<<" "<<num<<" : "<<dp[1-src][k-1+(t[1]==s[x])][num]<<endl;
        maxm(dp[src][k][num],dp[1-src][k-1+(t[1]==s[x])][num]+num);
    }
  //  cout<<x<<" "<<k<<" "<<num<<" : "<<dp[src][k][num]<<endl;
    if(x==n) maxm(ans,dp[src][k][num]);
}

int main(){
    cin>>n>>k>>s>>t;
    if(t[0]==t[1]) case1();
    s=' '+s;
    f(i,0,N)
        f(j,0,N)
            dp[0][i][j]=dp[1][i][j]=-N*N;
    dp[0][0][0]=0;
    f(i,1,n+1)
        f(j,0,k+1)
            f(l,0,n+1)
                calc(i,j,l);
    cout<<ans;
}