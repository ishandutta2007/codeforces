#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

const int MAXN = 100005;
int n;
int par[MAXN];
double sum[MAXN];
double sol[MAXN];
vector <int> v[MAXN];

int dfs (int cvor) {
	sum[cvor]=1;
	for (int i=0; i<v[cvor].size(); i++) {
		int sus=v[cvor] [i];
		if (sus==par[cvor]) continue;
		sum[cvor]+=dfs(sus);
	}
	return sum[cvor];
}

void rjesi (int cvor) {
	double val=0;
	for (int i=0; i<v[cvor].size(); i++) {
		int sus=v[cvor] [i];
		if (sus==par[cvor]) continue;
		val+=sum[sus];
	}
	for (int i=0; i<v[cvor].size(); i++) {
		int sus=v[cvor] [i];
		if (sus==par[cvor]) continue;
		sol[sus]=1+sol[cvor]+(val-sum[sus])/2;
		rjesi(sus);
	}
}

int main () {
	scanf("%d", &n);
	for (int i=2; i<=n; i++) {
		scanf("%d", &par[i]);
		v[par[i]].push_back(i);
	}
	dfs(1);
	sol[1]=1;
	rjesi(1);
	for (int i=1; i<=n; i++) {
		printf("%.1f ", sol[i]);
	}
	return 0;
}