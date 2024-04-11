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
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=3005;

int n,t,a[N],cnt[N][N];
ll ans=0;

int main(){
	cin>>t;
	while(t--){
	    ans=0;
	    cin>>n;
	    f(i,1,n+1) gett(a[i]);
	    f(i,1,n+1)
	        f(j,1,n+1)
	            cnt[i][j]=cnt[i-1][j]+(a[i]==j);
	    f(i,0,n)
	        f(j,0,i){
	            int u=a[j],v=a[i];
	            ans+=cnt[j-1][v]*(cnt[n][u]-cnt[i][u]);
	        }
	    cout<<ans<<'\n';
	}
}