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

const int maxn=1<<10;

int n,m;
int a[maxn][maxn];
ll col[maxn], row[maxn];
ll d[maxn], g[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++) {
			scanf("%d",&a[i][j]);
			col[j]+=a[i][j];
			row[i]+=a[i][j];
		}

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			d[0]+=1LL*(sqr(4*i-2)+sqr(4*j-2))*a[i][j];
		}
	}
	for (int i=1; i<=n; i++) {
		d[i]=d[i-1];
		for (int j=1; j<=n; j++) {
			d[i]+=1LL*(sqr(4*i-(4*(j-1)+2))-sqr(4*(i-1)-(4*(j-1)+2)))*row[j];
		}
	}
	ll curmn=d[0];
	int cx=0,cy=0;
	for (int i=1; i<=n; i++) 
		if (d[i]<d[cx]) {
			cx=i;
		}
	g[0]=d[cx];
	for (int i=1; i<=m; i++) {
		g[i]=g[i-1];
		for (int j=1; j<=m; j++) {
			g[i]+=1LL*(sqr(4*i-(4*(j-1)+2))-sqr(4*(i-1)-(4*(j-1)+2)))*col[j];
		}
		if (g[i]<g[cy]) {
			cy=i;
		}
	}
	cout << g[cy] << endl << cx << " " << cy << endl;
	return 0;
}