#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<x.F<<" , "<<x.S<<"}"<<endl
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

const int N=10005,inf=1e18;

int p1,p2,t1,t2,h,s,dp[N],f[N];

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>p1>>t1;
	cin>>p2>>t2;
	cin>>h>>s;
	fill(f,f+N,inf);
	int a1=0,a2=0,val=0;
	while(1){
		if(a1+t1<=a2+t2){
			a1+=t1;
			val+=p1-s;
		}
		else{
			a2+=t2;
			val+=p2-s;
		}
		if(a1 && a2) minm(f[val],max(a1,a2));
		//cout<<val<<" "<<a1<<" "<<a2<<endl;
		if(val>h) break; 
	}
	f_(i,N-2,0){
		minm(f[i],f[i+1]);
	}
	f(i,1,h+1){
		dp[i]=inf;
		f(j,0,i){
			if(p1+p2-s>=i-j){
				//eror(i);
				minm(dp[i],dp[j]+max(t1,t2));
				//eror(dp[j],max(t1,t2));
			}
			else{
				minm(dp[i],dp[j]+f[i-j-s]);
			}
		}
		minm(dp[i],(i+(p1-s)-1)/(p1-s)*t1);
		minm(dp[i],(i+(p2-s)-1)/(p2-s)*t2);
		//cout<<dp[i]<<" ";;
		//return 0;
	}
	cout<<dp[h];
}