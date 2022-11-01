#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, k;
int a[maxn];
vector<int> v[maxn];
int x, y;
int sum;
bool tag[maxn];
int cnt;

void dfs(int i, int fa){
	tag[i] = false;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		dfs(to, i);
		a[i] ^= a[to];
		tag[i] |= tag[to];
	}
	if(!tag[i] && a[i] == sum) tag[i] = true, cnt++;
	if(tag[i] && a[i] == 0) cnt++;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k), sum = cnt = 0;
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), v[i].clear(), sum ^= a[i];
		for(int i = 1;i < n;i++){
			scanf("%d%d", &x, &y);
			v[x].push_back(y), v[y].push_back(x);
		}
		if(sum == 0){
			puts("YES");
			continue;
		}
		if(n == 2 || k == 2){
			puts("NO");
			continue;
		}
		dfs(1, 0);
		puts(cnt > 1 ? "YES" : "NO");
	}
}