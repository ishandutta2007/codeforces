#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 998244353
#define N 20

int i,j,k,t;
ll n,m,f[666],g[666],sb,res;

void get(){
	int i,j,k;ll t1;
	unordered_map<ll,ll> mp[66];
	for(i=N;i>=1;i--){
		mp[i][i]++;
		f[i]+=m;
		for(j=i+1;j<=N;j++){
			vector<pair<ll,ll> >v;
			for(auto &[x,y]:mp[j]){
				t1=x*i/__gcd(x,1ll*i);
				if(t1>m*i)continue;
				f[j]+=-((m*i)/t1)*y;
				v.push_back({t1,-y});
			}
			for(auto &[t1,y]:v)mp[j][t1]+=y;
		}
	}
}

int main() {
	cin>>n>>m;
	get();
	for(i=1;i<=N;i++)g[i]=g[i-1]+f[i];
	for(i=1;i<=N;i++){
		for(j=2;j<=i;j++){
			g[i]-=g[i/j];
		}
	}
	for(i=N;i>=1;i--){
		sb=(ll)pow(n+.5,1.0/i)-(ll)pow(n+.5,1.0/(i+1));
		res+=sb*g[i];
	}
	cout<<res+1;
}