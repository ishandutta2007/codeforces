#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

vector<int> rb[300300];

int ctr[300300], cnt[300300], mxs[300300], p[300300];

void dfs(int u) {
	cnt[u] = 1;
	mxs[u] = 0;
	ctr[u] = u;
	for(int i = 0; i < (int)rb[u].size(); i++) {
		int v = rb[u][i];
		dfs(v);
		cnt[u] += cnt[v];
		mxs[u] = max(mxs[u], cnt[v]);
	}

	int sz = cnt[u], ms = sz >> 1;
	for(int i = 0; i < (int)rb[u].size(); i++) {
		int v = ctr[rb[u][i]];
		while(v != u) {
			int szp = sz - cnt[v];
			if(szp <= ms && mxs[v] <= ms) {
				break;
			} else {
				v = p[v];
			}
		}
		if(v != u) {
			ctr[u] = v;
			break;
		}
	}
}


int main() {

	int n, q;
	scanf("%d%d", &n, &q);
	for(int i = 1; i < n; i++) {
		int v;
		scanf("%d", &v);
		v--;
		rb[v].push_back(i);
		p[i] = v;
	}

	dfs(0);

	for(; q--; ) {
		int z;
		scanf("%d", &z);
		printf("%d\n", ctr[z - 1] + 1);
	}

	return 0;
}