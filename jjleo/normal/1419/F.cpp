#include <bits/stdc++.h>
#define maxn 1086

using namespace std;

int n;
int x[maxn], y[maxn];
map<int, vector<pair<int, int> > > mpx, mpy;//x y 
int col[maxn];
int cnt;

vector<int> v[maxn];
vector<pair<int, int> > a, b;

void dfs(int i){
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(!col[to]) col[to] = col[i], dfs(to);
	}
}

inline bool check(int t){
	for(int i = 1;i <= n;i++) col[i] = 0, v[i].clear();
	cnt = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(i == j) continue;
			if((x[i] == x[j] && abs(y[i] - y[j]) <= t) || (y[i] == y[j] && abs(x[i] - x[j]) <= t)) v[i].push_back(j);
		}
	}
	for(int i = 1;i <= n;i++) if(!col[i]) col[i] = ++cnt, dfs(i);
	if(cnt > 4) return false;
	if(cnt == 1) return true;
	if(cnt == 2){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(col[i] == col[j]) continue;
				if((x[i] == x[j] && (abs(y[i] - y[j]) + 1) / 2 <= t) || (y[i] == y[j] && (abs(x[i] - x[j]) + 1) / 2 <= t)) return true;
				if(abs(x[i] - x[j]) <= t && abs(y[i] - y[j]) <= t) return true;
			}
		}
	}else if(cnt == 3){
		a.clear();
		for(map<int, vector<pair<int, int> > >::iterator it = mpx.begin();it != mpx.end();++it){
			vector<pair<int, int> > v = it->second;
			for(int i = 1;i < v.size();i++) if(col[v[i].second] ^ col[v[i - 1].second]) a.push_back({v[i].second, v[i - 1].second});
		}
		for(map<int, vector<pair<int, int> > >::iterator it = mpy.begin();it != mpy.end();++it){
			vector<pair<int, int> > v = it->second;
			for(int i = 1;i < v.size();i++) if(col[v[i].second] ^ col[v[i - 1].second]) a.push_back({v[i].second, v[i - 1].second});
		}
		for(int i = 0;i < a.size();i++){
			int k = a[i].first, l = a[i].second;
			for(int j = 1;j <= n;j++){
				if(col[k] == col[j] || col[l] == col[j]) continue;
				if(x[k] == x[l]){
					if(abs(y[k] - y[j]) <= t && abs(y[l] - y[j]) <= t && abs(x[k] - x[j]) <= t) return true;
				}else{
					if(abs(x[k] - x[j]) <= t && abs(x[l] - x[j]) <= t && abs(y[k] - y[j]) <= t) return true;
				}
			} 
		}
	}else{
		a.clear();
		for(map<int, vector<pair<int, int> > >::iterator it = mpx.begin();it != mpx.end();++it){
			vector<pair<int, int> > v = it->second;
			for(int i = 1;i < v.size();i++) if(col[v[i].second] ^ col[v[i - 1].second]) a.push_back({v[i].second, v[i - 1].second});
		}
		for(map<int, vector<pair<int, int> > >::iterator it = mpy.begin();it != mpy.end();++it){
			vector<pair<int, int> > v = it->second;
			for(int i = 1;i < v.size();i++) if(col[v[i].second] ^ col[v[i - 1].second]) b.push_back({v[i].second, v[i - 1].second});
		}
		for(int i = 0;i < a.size();i++){
			int A = a[i].first, B = a[i].second;
			for(int j = 0;j < b.size();j++){
				int C = b[j].first, D = b[j].second;
				if(col[A] == col[C] || col[A] == col[D] || col[B] == col[C] || col[B] == col[D]) continue;
				if(1ll * (y[A] - y[C]) * (y[B] - y[C]) <= 0 && 1ll * (x[C] - x[A]) * (x[D] - x[A]) <= 0){
					if(abs(y[A] - y[C]) <= t && abs(y[B] - y[C]) <= t && abs(x[C] - x[A]) <= t && abs(x[D] - x[A]) <= t) return true;
				}
			}
		}
	}
	return false;
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%d%d", &x[i], &y[i]);
		mpx[x[i]].push_back({y[i], i}), mpy[y[i]].push_back({x[i], i});
	}
	for(map<int, vector<pair<int, int> > >::iterator it = mpx.begin();it != mpx.end();++it) sort(it->second.begin(), it->second.end());
	for(map<int, vector<pair<int, int> > >::iterator it = mpy.begin();it != mpy.end();++it) sort(it->second.begin(), it->second.end());
	int l = 1, r = 2e9 + 1, mid;
	while(l < r){
		mid = 1ll * l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d", l > 2e9 ? -1 : l);
}