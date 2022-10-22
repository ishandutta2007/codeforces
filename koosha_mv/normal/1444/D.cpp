#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1005;

int n,m,t,a[N],b[N];

bitset<N*N> dp[N];

int Main(){
	vector<int> v0,v1,h0,h1;
	int res=0,sum1=0,sum2=0,now=0;
	cin>>n;
	f(i,1,n+1){
		cin>>a[i];
	}
	cin>>m;	
	f(i,1,m+1){
		cin>>b[i];
	}
	if(n!=m) return cout<<"NO"<<endl,0;
	f(i,1,n+1){
		sum1+=a[i];
		dp[i]=dp[i-1] | (dp[i-1]<<a[i]);
	}
	if(sum1&1 || dp[n][sum1/2]==0) return cout<<"NO"<<endl,0;
	now=sum1/2;
	f_(i,n,1){
		if(dp[i-1][now]==1){
			h0.pb(a[i]);
		}
		else{
			now-=a[i];
			h1.pb(a[i]);
		}
	}
	f(i,1,n+1){
		sum2+=b[i];
		dp[i]=dp[i-1] | (dp[i-1]<<b[i]);
	}
	if(sum2&1 || dp[n][sum2/2]==0) return cout<<"NO"<<endl,0;
	now=sum2/2;
	f_(i,n,1){
		if(dp[i-1][now]==1){
			v0.pb(b[i]);
		}
		else{
			now-=b[i];
			v1.pb(b[i]);
		}
	}
	sort(h0.begin(),h0.end());
	sort(h1.begin(),h1.end());
	sort(v0.begin(),v0.end());
	sort(v1.begin(),v1.end());
	reverse(v0.begin(),v0.end());
	reverse(v1.begin(),v1.end());
	cout<<"YES"<<endl;
	int x=0,y=0;
	if(v0.size()>v1.size()) swap(v0,v1);
	if(h0.size()<h1.size()) swap(h0,h1);
	f(i,0,n+n){
		cout<<x<<" "<<y<<endl;
		int s=i/2;
		if(i%2==0){
			if(s<v0.size()){
				y+=v0[s];
			}
			else{
				y-=v1[s-v0.size()];
			}
		}
		else{
			if(s<h0.size()){
				x+=h0[s];
			}
			else{
				x-=h1[s-h0.size()];
			}
		}
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	dp[0][0]=1;
	cin>>t;
	while(t--){
		Main();
	}
}