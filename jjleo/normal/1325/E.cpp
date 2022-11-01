#include <bits/stdc++.h>
#define maxn 1000086
using namespace std;

int n, x;
vector<int> v[maxn];
int ans = maxn;
pair<int, int> q[maxn];
int l, r;
int dep[maxn];


int main(){
	scanf("%d", &n);
	while(n--){
		scanf("%d", &x);
		int p = 1, q = 1, j = x, sx = (int)ceil(sqrt(x));
		for(int i = 2;i <= sx && j != 1;i++){
			int cnt = 0;
			while(j % i == 0) j /= i, cnt++;
			if(cnt % 2) if(p == 1) p = i; else q = i;
		}
		if(j != 1) if(p == 1) p = j; else q = j;
		if(p == 1 && q == 1) return printf("1"), 0;
		v[p].push_back(q), v[q].push_back(p);
	}
	for(int i = 1;i <= 1000;i++){
		memset(dep, -1, sizeof(dep));
		l = 1, r = 0;
		q[++r] = {i, 0}, dep[i] = 0;
		while(l <= r){
			x = q[l].first;
			int fa = q[l++].second;
			for(int j = 0;j < v[x].size();j++){
				if(v[x][j] == fa) continue;
				if(dep[v[x][j]] == -1) dep[v[x][j]] = dep[x] + 1, q[++r] = {v[x][j], x};
				else ans = min(ans, dep[x] + dep[v[x][j]] + 1);
			}
		}
	}
	printf("%d", ans == maxn ? -1 : ans);
}