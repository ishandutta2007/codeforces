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

const int maxn=100100;

int n,m,mod,ost;
ll ans;
bool vis[maxn];
vector <int> e[maxn],v;



int dfs(int v) {
	int res=0;
	vis[v]=true;
	for (int i=0; i<e[v].size(); i++) if (!vis[e[v][i]]) res+=dfs(e[v][i]);
	return res+1;
}

int pw(int n, int k) {
	ll res=1;
	for (int i=0; i<k; i++) 
		res=(res*n)%mod;
	return res;
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	cin >> n >> m >> mod;
	for (int i=0; i<m; i++) {
		int x1,x2;
		cin >> x1 >> x2;
		e[x1].push_back(x2);
		e[x2].push_back(x1);
	}
	for (int i=1; i<=n; i++) if (!vis[i]) {
		v.push_back(dfs(i));
	}
	ans=1;
	for (int i=0; i<v.size(); i++)
		ans=(ans*v[i])%mod;
	ans*=pw(n,(int)v.size()-2);
	if (v.size()==1) ans=1;
	ans%=mod;
	cout << ans;
	return 0;
}