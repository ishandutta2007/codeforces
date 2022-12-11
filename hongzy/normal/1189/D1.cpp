#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 1e5 + 10;

int n, a[N], s[N], t[N], d[N], f[N];
vector<int> G[N];

int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; i ++) {
		scanf("%d%d", s + i, t + i);
		d[s[i]] ++; d[t[i]] ++;
//		G[s[i]].push_back(t[i]);
//		G[t[i]].push_back(s[i]); 
	}
//	for(int i = 1; i <= n; i ++) if(d[i] == 1) {
//		f[i] = 1;
//		for(int j = 0; j < G[i].size(); j ++) {
//			f[G[i][j]] = 1;
//		}
//	} 
	for(int i = 1; i <= n; i ++) if(d[i] == 2) {
//		int cnt = 0;
//		for(int j = 0; j < G[i].size(); j ++) {
//			if(!f[G[i][j]]) {
//				cnt ++;
//			}
//		}
//		if(cnt >= 2) {
			puts("NO"); return 0;
//		}
	} 
	puts("YES");
	return 0;
}