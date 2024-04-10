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

const int maxn=100;

int n,m,cnt,mn=2;
string a[maxn];
bool vis[maxn][maxn];

int f(int i, int j) {
	if (i<0 || i>=n || j<0 || j>=m) return 0;
	return a[i][j]=='#';
}

void dfs(int i, int j) {
	vis[i][j]=true;
	if (f(i,j+1) && !vis[i][j+1]) dfs(i,j+1);
	if (f(i,j-1) && !vis[i][j-1]) dfs(i,j-1);
	if (f(i+1,j) && !vis[i+1][j]) dfs(i+1,j);
	if (f(i-1,j) && !vis[i-1][j]) dfs(i-1,j);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) if (a[i][j]=='#') {
			cnt++;
			for (int ii=0; ii<n; ii++) for (int jj=0; jj<m; jj++) vis[ii][jj]=false;
			vis[i][j]=true;
			if (f(i+1,j)) dfs(i+1,j);
			else if (f(i-1,j)) dfs(i-1,j);
			else if (f(i,j+1)) dfs(i,j+1);
			else if (f(i,j-1)) dfs(i,j-1);
			for (int ii=0; ii<n; ii++) for (int jj=0; jj<m; jj++) if (!vis[ii][jj] && a[ii][jj]=='#') mn=1;
		}
	}
	if (cnt<3) cout << -1;
	else cout << mn;
	return 0;
}