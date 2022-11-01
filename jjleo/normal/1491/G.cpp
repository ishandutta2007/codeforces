#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n;
vector<vector<int> > v; 
int a[maxn];
bool vis[maxn];
vector<pair<int, int> > ans;

void solve(vector<int> a, vector<int> b){
	if(a.size() == 1 && b.size() == 1) return;
	ans.push_back({a[0], b[0]});
	for(int i = 1;i < b.size();i++) ans.push_back({a[0], b[i]});
	for(int i = 1;i < a.size();i++) ans.push_back({b[0], a[i]});
	ans.push_back({a[0], b[0]});
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	for(int i = 1;i <= n;i++){
		if(vis[i]) continue;
		int x = i;
		vector<int> w;
		while(!vis[x]){
			vis[x] = true;
			w.push_back(x);
			x = a[x];
		}
		v.push_back(w);
	}
	for(int i = 0;i + 1 < v.size();i += 2) solve(v[i], v[i + 1]);
	if(v.size() == 1){
		vector<int> a = v[0];
		ans.push_back({a[0], a[1]}), ans.push_back({a[1], a[2]}), swap(a[1], a[2]);
		for(int i = 3;i < a.size();i++) ans.push_back({a[2], a[i]});
		ans.push_back({a[0], a[1]}), ans.push_back({a[0], a[2]});
	}else if(v.size() & 1){
		vector<int> a;
		a.push_back(v[0][0]);
		solve(a, v.back());
	}
	printf("%d\n", ans.size());
	for(int i = 0;i < ans.size();i++) printf("%d %d\n", ans[i].first, ans[i].second);
}