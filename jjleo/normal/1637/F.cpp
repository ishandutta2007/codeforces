#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int n;
int h[maxn];
int mx[maxn], sx[maxn], id[maxn];
vector<int> v[maxn];
int x, y;
ll sum, ans = 1e18;

void dfs1(int i, int fa){
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		dfs1(to, i);
		int val = max(mx[to], h[to]);
		if(val > mx[i]) sx[i] = mx[i], mx[i] = val, id[i] = to;
		else sx[i] = max(sx[i], val);
	}
	sum += max(0, h[i] - mx[i]);
}

void dfs2(int i, int fa){
	int val = max(0, h[i] - mx[i]);
	sum -= val;
 	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		
		int val = max(0, h[to] - mx[to]);
		sum -= val;
		int Val = id[i] == to ? sx[i] : mx[i];
		Val = max(Val, h[i]);
		if(Val > mx[to]) sx[to] = mx[to], mx[to] = Val, id[to] = i;
		else sx[to] = max(sx[to], Val);
		sum += max(0, h[to] - mx[to]);
		
		if(id[i] == to) sum += max(0, h[i] - sx[i]);
		else sum += max(0, h[i] - mx[i]);
		
		dfs2(to, i);
		
		if(id[i] == to) sum -= max(0, h[i] - sx[i]);
		else sum -= max(0, h[i] - mx[i]);
		
		sum -= max(0, h[to] - mx[to]);
		sum += val;
	}
	sum += val;
	ans = min(ans, sum);
	
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &h[i]);
	if(n == 2) return printf("%d", max(h[1], h[2]) * 2), 0;
	for(int i = 1;i < n;i++){
		scanf("%d%d", &x, &y);
		v[x].push_back(y), v[y].push_back(x);
	}
	dfs1(1, 0);
	dfs2(1, 0);
	printf("%lld", ans + *max_element(h + 1, h + 1 + n));
}