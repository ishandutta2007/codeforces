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

const int maxn=2100;
const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};

int n,c1,c2;
int a[maxn][maxn];
bool vis[maxn][maxn];


void bfs(int x, int y) {
	int mxx,mxy,mnx,mny;
	mxx=mxy=-1; mny=mnx=n+1;

	queue <pair<int,int>> q;
	q.push(make_pair(x,y));
	vis[x][y]=true;
	while (!q.empty()) {
		x=q.front().first, y=q.front().second;
		mxx=max(mxx,x); mxy=max(mxy,y); 
		mnx=min(mnx,x); mny=min(mny,y);
		q.pop();
		for (int i=0; i<4; i++) 
			if (!vis[x+dx[i]][y+dy[i]] && a[x+dx[i]][y+dy[i]]) {
				q.push(make_pair(x+dx[i],y+dy[i]));
				vis[x+dx[i]][y+dy[i]]=true;
			}
	}
	if (a[mnx][mny] && a[mxx][mxy]) c2++;
	else c1++;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			scanf("%d",&a[i][j]);
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (!vis[i][j] && a[i][j]==1) bfs(i,j);
		}
	}
	cout << c1 << ' ' << c2;
	return 0;
}