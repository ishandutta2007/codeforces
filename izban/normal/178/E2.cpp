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
const double eps=1e-5;


int n,c1,c2;
int a[maxn][maxn];
bool vis[maxn][maxn];
pair<int,int> k[maxn];



void bfs(int x, int y) {
	int mxx,mxy,mnx,mny,sum=0;
	mxx=mxy=-1; mny=mnx=n+1;

	queue <pair<int,int>> q;
	q.push(make_pair(x,y));
	vis[x][y]=true;
	while (!q.empty()) {
		sum++;
		x=q.front().first, y=q.front().second;
		k[y].first=min(k[y].first,x);
		k[y].second=max(k[y].second,x);
		mxx=max(mxx,x); mxy=max(mxy,y); 
		mnx=min(mnx,x); mny=min(mny,y);
		q.pop();
		for (int i=0; i<4; i++) 
			if (!vis[x+dx[i]][y+dy[i]] && a[x+dx[i]][y+dy[i]]) {
				q.push(make_pair(x+dx[i],y+dy[i]));
				vis[x+dx[i]][y+dy[i]]=true;
			}
	}

	
	bool f=sqr(mny-mxy)+sqr(k[mny].first-k[mxy].second)<sqr(mxy-mny+1) && sum>sqr(mxx-mnx)*0.75 && sum<sqr(mxx-mnx)*0.80;
	if (f) c1++;
	else c2++;
	/*bool f=k[mny]!=k[mxy] || k[mny+1]!=k[mxy-1] || k[mny+2]!=k[mxy-2];
	if (a[mnx][mny] && a[mxx][mxy]) c2++;
	else if (f) c2++;
	else if (sum<sqr(mxx-mnx)*0.64) c2++;
	else c1++;*/
	/*bool f=true;
	for (int i=mny; i<mxy; i++) 
		f=f&&(abs((k[i].second+k[i].first)/2.0-(k[i+1].second+k[i+1].first)/2.0)<eps);
	bool g=true;
	for (int i=mny; i<mxy; i++)
		g=g && (abs(k[i].first-k[i+1].first)==1);*/
	/*if (a[mnx][mny] && a[mxx][mxy]) c2++;
	else if (!f) c2++;
	else if (g) c2++;
	else c1++;*/
	for (int i=mny; i<=mxy; i++) k[i]=make_pair(n+1,-1);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n;
	for (int i=0; i<maxn; i++) k[i]=make_pair(n+1,-1);
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