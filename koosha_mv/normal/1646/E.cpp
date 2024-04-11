#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
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
#define int ll

const int N=(1<<20)+9,lg=21;

int n,m,a[N],mark[N],dp[lg+9];
ll ans=1;

main(){
	cin>>n>>m;
	f(mask,1,(1<<lg)){
		int lcm=1,last=-1,frst=-1;
		f(i,1,lg+1){
			if(bit(mask,i-1)==0) continue ;
			if(frst==-1) frst=i;
			last=i;
			lcm=lcm*i/__gcd(lcm,i);
		}
		int res=m/(lcm/frst);
		if(nb(mask)&1) dp[last]+=res;
		else dp[last]-=res;
	}
	f(i,1,lg+1){
		dp[i]+=dp[i-1];
	}
	f(i,2,n+1){
		if(!mark[i]){
			int cnt=0;
			for(int j=i;j<=n;j*=i){
				cnt++;
				mark[j]=1;
			}
			ans+=dp[cnt];
		}
	}
	cout<<ans;
}