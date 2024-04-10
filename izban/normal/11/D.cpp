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

const int maxn=20;

int n,m,a[maxn][maxn];
ll d[1<<maxn][maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int x,y;
		cin >> x >> y;
		a[x-1][y-1]=a[y-1][x-1]=1;
	}

	ll ans=0;
	for (int i=0; i<n; i++) d[1<<i][i]=1;
	for (int mask=0; mask<1<<n; mask++) {
		int start=-1, cnt=0;
		for (int i=0; i<n; i++) 
			if (mask&(1<<i)) {
				if (start==-1)
					start=i;
				cnt++;
			}
		for (int i=0; i<n; i++) if (mask&(1<<i)) {
			for (int j=start+1; j<n; j++) if (!(mask&(1<<j)) && a[i][j]) {
				d[mask+(1<<j)][j]+=d[mask][i];
			}
			if (a[i][start] && cnt>2)
				ans+=d[mask][i];
		}
	}

	cout << ans/2;
	return 0;
}