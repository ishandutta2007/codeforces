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
 
const int N=2e5+9,Lg=62,S=2;

int T,n,k,ans,a[N],dp[N]; 

int lb(int x){
    int l=0,r=n+1,mid;
    while(l+1<r){
        mid=(l+r)/2;
        if(a[mid]<x) l=mid;
        else r=mid;
    }
    return l;
}

int main(){
    cin>>T;
    while(T--){
        ans=0;
        cin>>n>>k;
        f(i,1,n+1) gett(a[i]);
        f(i,0,n){
            int x;
            gett(x);
        }
        sort(a+1,a+1+n);
        f(i,1,n+1){
            int p=lb(a[i]-k);
            dp[i]=max(dp[i-1],i-p);
            maxm(ans,i-p+dp[p]);
        }
        cout<<ans<<'\n';
    }
}