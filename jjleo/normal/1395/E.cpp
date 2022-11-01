#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef unsigned long long ull;

const int M = 131;

int n, m, k;
vector<pair<int, int> > v[maxn];
int x, y, z;
ull a[10][10], sum[maxn], val, Sum;
int ans;

void dfs(int i){
	if(i > k){
		ans += val == Sum;
		return;
	}
	for(int j = 1;j <= i;j++){
		val += a[i][j];
		dfs(i + 1);
		val -= a[i][j];
	}
}

int main(){
	scanf("%d%d%d", &n, &m, &k);
	sum[0] = 1;for(int i = 1;i <= n;i++) sum[i] = sum[i - 1] * M, Sum += sum[i];
	while(m--){
		scanf("%d%d%d", &x, &y, &z);
		v[x].push_back({z, y});
	}
	for(int i = 1;i <= n;i++){
		if(v[i].size() == 0) return printf("0"), 0;
		sort(v[i].begin(), v[i].end());
		for(int j = 0;j < v[i].size();j++){
			a[v[i].size()][j + 1] += sum[v[i][j].second];
		}
	}
	dfs(1);
	printf("%d", ans);
}