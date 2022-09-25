#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;



#define sqr(x) ((x)*(x))

string s;
int c;
int d[600][600];
int z[600][600];
const int inf=int(1e9);
pair<int,int> p[600][600];

void rec(int x, int y, bool f) {
	if (p[x][y].first!=0 && p[x][y].second!=0) rec(p[x][y].first,p[x][y].second,false);
	for (int i=p[x][y].first; i<x; i++) 
		cout << (i<=(x+p[x][y].first-1)/2? s[i] : s[x+p[x][y].first-1-i]);
	if (!f) cout << '+';
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	cin >> s >> c; int n=s.length();
	for (int i=0; i<n; i++) 
		for (int j=i; j<n; j++) 
			for (int k=0; k<=(j-i)/2; k++)
				if (s[i+k]!=s[j-k]) d[i+1][j+1]++;
	for (int i=0; i<=n; i++) for (int j=0; j<=n; j++) z[i][j]=inf;
	z[0][0]=0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<=i; j++) {
			for (int k=1; i+k<=n; k++) {
				if (z[i+k][j+1]>z[i][j]+d[i+1][i+k]) {
					z[i+k][j+1]=z[i][j]+d[i+1][i+k];
					p[i+k][j+1]=make_pair(i,j);
				}
			}
		}
	}
	int mn=inf,a=0;
	for (int i=1; i<=c; i++) 
	if (z[n][i]<mn) {
		mn=z[n][i];
		a=i;
	}
	cout << mn << endl;
	rec(n,a,true);
	return 0;
}