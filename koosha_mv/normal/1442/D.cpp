#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
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

const int N=3010,lg=13;

int n,p,k,t[N];
ll ans,a[N][N],dp[lg][N];

void add(int x,int c){
    f_(i,k,t[x])
        maxm(dp[c][i],dp[c][i-t[x]]+a[x][t[x]]);
}
void G(int l,int r,int c){
    if(l+1==r){
        f(i,1,min(t[l],k)+1)
            maxm(ans,a[l][i]+dp[c][k-i]);
        return;
    }
    int mid=(l+r)>>1;
    f(i,0,k+1) dp[c+1][i]=dp[c][i];
    f(i,mid,r) add(i,c+1);
    G(l,mid,c+1);
    f(i,0,k+1) dp[c+1][i]=dp[c][i];
    f(i,l,mid) add(i,c+1);
    G(mid,r,c+1);
}
int main(){
    cin>>n>>k;
    f(i,0,n){
        int x;
        gett(t[i]);
        f(j,0,t[i]){
            gett(x);
            if(j<N-3) a[i][j+1]=a[i][j]+x;
        }
    }
    G(0,n,0);
    cout<<ans;
}