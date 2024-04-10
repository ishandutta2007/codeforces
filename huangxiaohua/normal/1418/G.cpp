#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<pair<ll,ll> ,int> mp;
int i,j,k,n,m,t,a[500500],b[500500],it=1;
ll x[500500],y[500500],f[500500],res;

int main() {
	ios::sync_with_stdio(0);
	mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()+1);
	for(i=1;i<=500000;i++)f[i]=rng();
	cin>>n;
	mp[{0,0}]++;
	for(i=1;i<=n;i++){
		cin>>a[i];b[a[i]]++;
		while(b[a[i]]>3){
			b[a[it]]--;mp[{x[it-1],y[it-1]}]--;it++;
		}
		x[i]=x[i-1]^f[a[i]]&~y[i-1];
		y[i]=y[i-1]^f[a[i]]&~x[i];
		res+=mp[{x[i],y[i]}]++;
	}
	cout<<res;
}