#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
mt19937_64 rng(time(0));
const double PI = acos(-1.L);
const int mn = 1e6+10;
const ll mod = 998244353;

bool isp[mn];
ll a[mn];
void solve(){
	int n,e;
	cin>>n>>e;
	ll ans=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==1)a[i]=0;
		else if(isp[a[i]])a[i]=1;
		else a[i]=2;
	}
	for(int d=0;d<e;d++){
		int num=0;
		for(int i=0,j=0;d+i*e<n;i++){
			num+=a[d+i*e];
			while(num>=2)num-=a[d+j*e],j++;
			ans+=max(0,i-j);
		}
	}
	for(int d=0;d<e;d++){
		int num=0;
		for(int i=0,j=0;d+i*e<n;i++){
			num+=a[d+i*e];
			while(num>=1)num-=a[d+j*e],j++;
			ans-=max(0,i-j);
		}
	}
	printf("%lld\n",ans);
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	
	memset(isp,1,sizeof(isp));
	for(int i=2;i*i<mn;++i)if(isp[i])for(int j=i*i;j<mn;j+=i)isp[j]=0;

	int tc;
	cin>>tc;
	while(tc--)solve();
}