#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

const int N = 100005, inf = 1e9;

int n, m, q, w[15], c[1<<12], v[1<<12][105];

char ipt[15];

int getipt () {
	int T = 0;
	scanf("%s",ipt);
	for(int i=0;i<n;i++) {
		T += (1<<i) * (ipt[i] == '1');
	}
	return T;
}

int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=0;i<n;i++) {
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=m;i++) {
		c[getipt()]++;
	}
	for(int i=0;i<(1<<n);i++) {
		for(int j=0;j<(1<<n);j++) {
			int V = 0;
			for(int k=0;k<n;k++) {
				if(!((1<<k) & j)) V += w[k];
			}
			if(V > 100) continue;
			v[i^j][V] += c[i];
		}
	}
	for(int i=0;i<(1<<n);i++) {
		for(int j=1;j<=100;j++) {
			v[i][j] += v[i][j-1];
		}
	}
	for(int i=1;i<=q;i++) {
		int T = getipt(), V;
		scanf("%d",&V);
		printf("%d\n",v[T][V]);
	}
}