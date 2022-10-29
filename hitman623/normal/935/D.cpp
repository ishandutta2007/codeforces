#include <bits/stdc++.h>

#define int          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii 		vector<pii>
#define mi 			map<int,int>
#define mii			map<int,pii>	
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
using namespace std;
int expo(int a,int n,int mod){
	int ans=1;
	while(n){
		if(n&1) ans=(1LL*ans*a)%mod;
		a=(1LL*a*a)%mod;
		n>>=1;
	}
	return ans;
}
int n,m,ans=0,cur=1,s1[100005],s2[100005];
void solve(){
	cin>>n>>m;
	int d=(m*(m-1))/2;
	d%=hell;
	rep(i,0,n){
		cin>>s1[i];
	}
	rep(i,0,n){
		cin>>s2[i];
	}
	rep(i,0,n){
		if(s1[i]==0 && s2[i]==0){
			int h=(d*expo(m*m%hell,hell-2,hell))%hell;
			ans=(ans+cur*h)%hell;
			cur*=expo(m,hell-2,hell);
			cur%=hell;
		}
		else if(s1[i]==0){
			int h=((m-s2[i])*expo(m,hell-2,hell))%hell;
			ans=(ans+cur*h)%hell;
			cur*=expo(m,hell-2,hell);
			cur%=hell;
		}
		else if(s2[i]==0){
			int h=((s1[i]-1)*expo(m,hell-2,hell))%hell;
			ans=(ans+cur*h)%hell;
			cur*=expo(m,hell-2,hell);
			cur%=hell;			
		}
		else if(s1[i]<s2[i]) break;
		else if(s1[i]>s2[i]){
			ans=(ans+cur)%hell;
			break;
		}
	}
	cout<<ans;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
	return 0;
}