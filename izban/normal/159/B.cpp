#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <ctime>

using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

const int maxn=1100;

int n,m,ans1,ans2;
int a[maxn][maxn],b[maxn][maxn];
string s;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		int x1,x2;
		cin >> x2 >> x1;
		a[x1][0]++; a[x1][x2]++;
	}
	for (int i=0; i<m; i++) {
		int x1,x2;
		cin >> x2 >> x1;
		b[x1][0]++; b[x1][x2]++;
	}
	for (int i=1; i<=1000; i++) {
		ans1+=min(a[i][0],b[i][0]);
		for (int j=1; j<=1000; j++) {
			ans2+=min(a[i][j],b[i][j]);
		}
	}
	cout << ans1 << ' ' << ans2;
	//cout << endl << clock();
	return 0;
}