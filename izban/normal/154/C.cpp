#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <string>
#include <ctime> 
#include <set>
#include <sstream>
#include <queue>

#define sqr(x) ((x)*(x))
#define ll long long

using namespace std;

const int maxn=1000100;

const int q=1000000007;
int n,m,u[maxn],v[maxn];
ll p[maxn],hsh[maxn],ans;

map <ll,ll> mp;

int main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	p[0]=1;
	for (int i=1; i<maxn; i++) p[i]=p[i-1]*q;
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		cin >> u[i] >> v[i];
		hsh[u[i]]+=p[v[i]];
		hsh[v[i]]+=p[u[i]];
	}
	/*for (int i=1; i<=n; i++) mp[hsh[i]]++;
	for (map<ll,ll>::iterator it=mp.begin(); it!=mp.end(); it++) {
		ans+=it->second*(it->second-1)/2;
	}*/
	for (int i=0; i<m; i++) {
		ans+=hsh[u[i]]+p[u[i]]==hsh[v[i]]+p[v[i]];
	}
	sort(hsh+1,hsh+n+1);
	hsh[n+1]=hsh[n]+1;
	ll l=1;
	for (ll i=1; i<=n; i++) {
		if (hsh[i]!=hsh[i+1]) {
			ans+=(i-l+1)*(i-l)/2;
			l=i+1;
		}
	}
	cout << ans;
	return 0;
}