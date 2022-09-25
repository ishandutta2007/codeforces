#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <string>
#include <ctime> 
#include <cstdlib>
#include <set>
#include <sstream>
#include <queue>
#include <functional>
#include <memory>
#include <assert.h>

#define sqr(x) ((x)*(x))
#define ll long long

using namespace std;

#pragma comment(linker,"/STACK:64000000")

const int maxn=61, mod=1000000007;
const double eps=1e-9;

int n,m,r;
int a[maxn][maxn][maxn],w[maxn][maxn],ans[maxn][maxn][maxn];


int main() { 
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

	scanf("%d%d%d",&n,&m,&r);
	for (int i=0; i<m; i++)
		for (int j=0; j<n; j++)
			for (int k=0; k<n; k++)
				scanf("%d",&a[i][j][k]);
	
	for (int i=0; i<maxn; i++) for (int j=0; j<maxn; j++) for (int k=0; k<maxn; k++) ans[i][j][k]=mod;

	for (int l=0; l<m; l++) {
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				w[i][j]=a[l][i][j];
		for (int k=0; k<n; k++) 
			for (int i=0; i<n; i++)
				for (int j=0; j<n; j++)
					w[i][j]=min(w[i][j],w[i][k]+w[k][j]);
		for (int i=0; i<n; i++) 
			for (int j=0; j<n; j++)
				ans[0][i][j]=min(ans[0][i][j],w[i][j]);
	}

	for (int i=1; i<maxn; i++) {
		for (int j=0; j<n; j++)
			for (int k=0; k<n; k++)
				for (int l=0; l<n; l++)
					ans[i][j][k]=min(ans[i][j][k],ans[i-1][j][l]+ans[0][l][k]);
	}

	for (int i=0; i<r; i++) {
		int s,t,k;
		scanf("%d%d%d",&s,&t,&k);
		printf("%d\n",ans[min(k,n)][s-1][t-1]);
	}

    return 0;
}