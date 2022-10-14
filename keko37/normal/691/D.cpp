#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int n, m, cnt=1, x, y;
int l[1000005];
int bio[1000005];
int ind[1000005];

vector <int> v[1000005];
vector <int> p[1000005];

void dfs (int pos) {
	for (int i=0; i<v[pos].size(); i++) {
		if (bio[v[pos] [i]]==0) {
			bio[v[pos] [i]]=cnt;
			dfs(v[pos] [i]);
		}
	}
}

int main () {
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++) {
		scanf("%d", &l[i]);
	}
	for (int i=0; i<m; i++) {
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i=1; i<=n; i++) {
		if (bio[i]==0) {
			bio[i]=cnt;
			dfs(i);
			cnt++;
		}
		p[bio[i]].push_back(l[i]);
	}
	for (int i=1; i<cnt; i++) {
		sort(p[i].begin(), p[i].end());
		reverse(p[i].begin(), p[i].end());
	}
	for (int i=1; i<=n; i++) {
		cout << p[bio[i]] [ind[bio[i]]] << " ";
		ind[bio[i]]++;
	}
	return 0;
}