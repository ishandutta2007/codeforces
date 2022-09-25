#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>


using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

int gcd(int a, int b) {
	while (b) b^=a^=b^=a%=b;
	return a;
}

ll max(ll a, ll b) {
	if (a>b) return a;
	else return b;
}

const int maxn=200;

int n,u,r;
int a[maxn],b[maxn],k[maxn],p[maxn];
ll ans=-1000000000000000;

void check() {
	ll res=0;
	for (int i=0; i<n; i++) {
		res+=(ll)a[i]*k[i];
	}
	ans=max(ans,res);
}

void dfs(int x) {
	if (x==u) {
		check();
	} else {
		if ((u-x)%2==0) check();
		else {
			for (int i=0; i<n; i++) {
				a[i]^=b[i];
			}
			check();
			for (int i=0; i<n; i++) {
				a[i]^=b[i];
			}
		}
		if (x<u-1) {
			int c[101];
			for (int i=0; i<n; i++) {
				a[i]^=b[i];
			}
			for (int i=0; i<n; i++) c[i]=a[i];
			for (int i=0; i<n; i++) {
				a[i]=c[p[i]-1]+r;
			}
			dfs(x+2);
			for (int i=0; i<n; i++)
				a[i]=c[i]^b[i];
		}
		if (x==u-1) {
			for (int i=0; i<n; i++) {
				a[i]^=b[i];
			}
			dfs(x+1);
			for (int i=0; i<n; i++) {
				a[i]^=b[i];
			}
		}
		int c[101];
		for (int i=0; i<n; i++) c[i]=a[i];
		for (int i=0; i<n; i++) {
			a[i]=c[p[i]-1]+r;
		}
		dfs(x+1);
		for (int i=0; i<n; i++)
			a[i]=c[i];
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> u >> r;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	for (int i=0; i<n; i++) {
		cin >> b[i];
	}
	for (int i=0; i<n; i++) {
		cin >> k[i];
	}
	for (int i=0; i<n; i++) {
		cin >> p[i];
	}
	dfs(0);
	cout << ans;
	return 0;
}