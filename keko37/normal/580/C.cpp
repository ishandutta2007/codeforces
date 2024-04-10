#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>

using namespace std;

int n, m;
int cat[100005];
vector <int> v[100005];
int l[100005];
int sol;

void dfs (int x, int par) {
	if (cat[x]) {
		if (cat[par]) l[x]=l[par]+1; else l[x]=1;
	} else {
		l[x]=0;
	}
	if (l[x]>m) return;
	for (int i=0; i<v[x].size(); i++) {
		if (l[v[x] [i]]==-1) {
			dfs(v[x] [i], x);
		}
	}
	if (v[x].size()==1 && x!=1) sol++;
}

int main () {
	memset(l, -1, sizeof l);
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> cat[i];
	}
	for (int i=0; i<n-1; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	l[1]=0;
	dfs(1, 1);
	cout << sol;
	return 0;
}