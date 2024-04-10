#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n, k;
vector<int> v[maxn];
int sum, mx;

int dfs(int i){
	int val = 0;
	for(auto to : v[i]){
		int x = dfs(to) + 1;
		if(x == mx && i != 1) sum++;
		else val = max(val, x);
	}
	return val;
}

bool check(int mid){
	mx = mid, sum = 0;
	dfs(1);
	return sum <= k;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		for(int i = 1;i <= n;i++) v[i].clear();
		for(int i = 2;i <= n;i++){
			int x;
			scanf("%d", &x);
			v[x].push_back(i);
		}
		int l = 1, r = n - 1, mid;
		while(l < r){
			mid = l + r >> 1;
			if(check(mid)) r = mid;
			else l = mid + 1;
		}
		printf("%d\n", l);
	}
}