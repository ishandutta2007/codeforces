#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n, m, K;
vector<int> v;
int l[maxn], r[maxn], pcnt[maxn];
vector<int> a[maxn], b[maxn];
int f[maxn], g[maxn];
bool tag[maxn];

int main(){
	scanf("%d%d%d", &n, &m, &K);
	for(int i = 1;i <= n;i++){
		scanf("%d%d", &l[i], &r[i]);
		v.push_back(l[i]), v.push_back(++r[i]);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for(int i = 1;i <= n;i++) a[lower_bound(v.begin(), v.end(), l[i]) - v.begin() + 1].push_back(lower_bound(v.begin(), v.end(), r[i]) - v.begin() + 1);
	for(int i = 1;i < (1 << K);i++) pcnt[i] = pcnt[i >> 1] ^ (i & 1);
	for(int i = 1;i < (1 << K);i++) f[i] = -1e9;
	for(int i = 1;i < v.size();i++){
		for(int j = 0;j < b[i].size();j++){
			int id = b[i][j];
			tag[id] = false;
			for(int k = 0;k < (1 << K);k++) g[k] = -1e9;
			for(int k = 0;k < (1 << K);k++) g[(k | (1 << id)) ^ (1 << id)] = max(g[(k | (1 << id)) ^ (1 << id)], f[k]);
			for(int k = 0;k < (1 << K);k++) f[k] = g[k];
		}
		for(int j = 0;j < a[i].size();j++){
			int id = 0;
			while(tag[id]) id++;
			tag[id] = true;
			b[a[i][j]].push_back(id);
			for(int k = 0;k < (1 << K);k++) g[k] = -1e9;
			for(int k = 0;k < (1 << K);k++) g[k] = max(g[k], f[k]), g[k | (1 << id)] = max(g[k | (1 << id)], f[k]);
			for(int k = 0;k < (1 << K);k++) f[k] = g[k];
		}
		for(int j = 0;j < (1 << K);j++) if(pcnt[j]) f[j] += v[i] - v[i - 1];
	}
	int ans = 0;
	for(int i = 0;i < (1 << K);i++) ans = max(ans, f[i]);
	printf("%d", ans);
}