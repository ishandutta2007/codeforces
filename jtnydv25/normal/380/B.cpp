#include <bits/stdc++.h>
using namespace std;

const int N = 7e3 + 10;
const int M = 2e5 + 10;
bool pw2[M];
int lft[M], rgt[M];
bool came[N];
int l[N], r[N], X[N], lvl[N], type[N];
int L[N], R[N];
int T[N], V[N];
set<int> present;
int compress[1000006];
int main(){
	for(int i = 0; i < 20; i++)
		if((1 << i) < M) pw2[1 << i] = 1;
	int curr = 0;
	for(int i = 1; i < M; i++){
		if(pw2[i]){
			lft[i] = curr + 1;
			rgt[i] = curr + 2;
			curr += 2;
		}
		else{
			lft[i] = rgt[i] = curr + 1;
			curr++;
		}
	}
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++){
		scanf("%d", type + i);
		if(type[i] == 1){
			scanf("%d %d %d %d", lvl + i, l + i, r + i, X + i);
			present.insert(X[i]);
		}
		else{
			scanf("%d %d", T + i, V + i);
		}
	}

	int cnt = 0;
	for(int x : present) compress[x] = ++cnt;
	for(int i = 1; i <= m; i++){
		X[i] = compress[X[i]];
		if(type[i] == 2){
			int t = T[i];
		 	int v = V[i];
			L[t] = R[t] = v;

			for(int j = t + 1; j <= n; j++){
				L[j] = lft[L[j - 1]];
				R[j] = rgt[R[j - 1]];
			}

			memset(came,0, sizeof came);
			for(int j = 1; j < i; j++){
				if(type[j] == 1 && lvl[j] >= t){
					int level = lvl[j];
					if(!(l[j] > R[level] || L[level] > r[j]))
						came[X[j]] = 1;
				}
			}
			int ans = 0;
			for(int j = 1; j <= cnt; j++) ans += came[j];
			printf("%d\n", ans);
		}
	}
}