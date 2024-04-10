#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>


using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

const int maxn=600;
int n,m;
int row[maxn],col[maxn],a[maxn][maxn],sum[maxn][maxn];
ll ans=-1000000000,d[maxn][maxn];

void precalc() {
	sum[0][0]=a[0][0];
	for (int i=1; i<n; i++) sum[i][0]=sum[i-1][0]+a[i][0];
	for (int i=1; i<m; i++) sum[0][i]=sum[0][i-1]+a[0][i];
	for (int i=1; i<n; i++)
		for (int j=1; j<m; j++)
			sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+a[i][j];
}

ll getsum(int i1, int j1, int i2, int j2) {
	ll ans=sum[i2][j2]-(i1?sum[i1-1][j2]:0)-(j1?sum[i2][j1-1]:0)+(i1 && j1?sum[i1-1][j1-1]:0);
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	scanf("%d%d",&n,&m);
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			scanf("%d",&a[i][j]);
			row[i]+=a[i][j];
			col[j]+=a[i][j];
		}
	}
	precalc();
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			//d[i][j]=a[i][j]+a[i][j+1]+a[i][j+2]+a[i+1][j+2]+a[i+2][j+2]+a[i+2][j+1]+a[i+2][j];
			//ans=max(ans,d[i][j]);
			d[i][j]=a[i][j];
		}
	}

	for (int k=3; k<=min(n,m); k+=2) {
		for (int i=0; i<n-k+1; i++) {
			for (int j=0; j<m-k+1; j++)  {
				d[i][j]=getsum(i,j,i+k-1,j+k-1)-a[i+1][j]-d[i+1][j+1];
				ans=max(d[i][j],ans);
			}
		}
	}
	cout << ans;
	return 0;
}