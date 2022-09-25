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
const int dx[9]={1,1,1,0,0,0,-1,-1,-1};
const int dy[9]={1,0,-1,1,0,-1,1,0,-1};

int n,m;
int a[maxn][maxn];

void check(int x, int y, int k) {
	int sum=0;
	for (int i=0; i<9; i++)
		sum+=a[x+dx[i]][y+dy[i]];
	if (sum==9) {
		cout << k+1;
		exit(0);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int x,y;
		cin >> x >> y;
		a[x][y]=1;
		for (int j=0; j<9; j++)
			check(x+dx[j],y+dy[j],i);
	}
	cout << -1;
	return 0;
}