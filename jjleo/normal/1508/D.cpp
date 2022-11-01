#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
int x[maxn], y[maxn], a[maxn];
vector<pair<double, int> > v;
int fa[maxn];
int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
vector<pair<int, int> > ans;

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d%d%d", &x[i], &y[i], &a[i]), fa[i] = i;
	int id = 0;
	for(int i = 1;i <= n;i++) if(a[i] ^ i){
		if(id == 0 || (pair<int, int>){x[i], y[i]} < (pair<int, int>){x[id], y[id]}) id = i;
	}
	if(!id) return printf("0"), 0;
	for(int i = 1;i <= n;i++) if((a[i] ^ i) && (i ^ id)) v.push_back({atan2(y[i] - y[id], x[i] - x[id]), i});
	sort(v.begin(), v.end());
	for(int i = 1;i <= n;i++) if(fa[i] == i){
		int x = a[i];
		while(x ^ i){
			fa[x] = i;
			x = a[x];
		}
	}
	for(int i = 0;i + 1 < v.size();i++){
		int x = v[i].second, y = v[i + 1].second;
		int fx = find(x), fy = find(y);
		if(fx ^ fy){
			fa[fx] = fy;
			swap(a[x], a[y]), ans.push_back({x, y}); 
		} 
	}
	int x = a[id];
	while(x ^ id){
		ans.push_back({id, x});
		x = a[x];
	}
	printf("%d\n", ans.size());
	for(int i = 0;i < ans.size();i++) printf("%d %d\n", ans[i].first, ans[i].second);
}