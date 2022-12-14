#include <bits/stdc++.h>

using namespace std;

int N;
int a[(int)2e5 + 4], dep[(int)2e5 + 4];
int lca[(int)2e5 + 4][24];
vector<vector<int>> way((int)2e5 + 4);
vector<vector<int>> col((int)2e5 + 4);
int top[(int)2e5 + 4], cnt[(int)2e5 + 4];
int no[(int)2e5 + 4];

void dfs(int x, int pr, int far){
	dep[x] = far;
	for(int i = 1; i < 24; ++i){
		lca[x][i] = lca[lca[x][i - 1]][i - 1];
	}
	for(auto&nxt:way[x]){
		if(nxt != pr){
			lca[nxt][0] = x;
			dfs(nxt, x, far + 1);
		}
	}
}

set<int> sol(int x, int pr){
	set<int> rv;
	int s = -1, same = 0;
	for(auto&nxt:way[x]){
		if(nxt != pr){
			set<int> now = sol(nxt, x);
			auto p = now.lower_bound(a[x]);
			if(p != now.end() && *p == a[x]){
				s = nxt; ++same;
			}
			if((int)rv.size() < (int)now.size()){
				swap(rv, now);
			}
			for(auto&i:now){
				rv.insert(i);
			}
		}
	}
	auto p = rv.lower_bound(a[x]);
	int cnt = (top[a[x]] != x) + same;
	if(cnt >= 2){
		cout << 0; exit(0);
	}
	if(top[a[x]] != x){
		no[x] += 1;
	}
	if(s != -1){
		no[1] += 1;
		no[s] -= 1;
	}
	rv.insert(a[x]);
	return rv;
}

int up(int x, int h){
	for(int i = 20; i >= 0; --i){
		if(dep[x] - (1 << i) >= h){
			x = lca[x][i];
		}
	}
	return x;
}

int getlca(int x, int y){
	for(int i = 20; i >= 0; --i){
		if(lca[x][i] != lca[y][i]){
			x = lca[x][i];
			y = lca[y][i];
		}
	}
	if(x != y){
		x = lca[x][0];
	}
	return x;
}

void Dfs(int x, int pr){
	for(auto&nxt:way[x]){
		if(nxt != pr){
			no[nxt] += no[x];
			Dfs(nxt, x);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	vector<int> srt(N);
	for(int i = 1; i <= N; ++i){
		cin >> a[i];
		srt[i - 1] = a[i];
	}
	sort(srt.begin(), srt.end());
	srt.erase(unique(srt.begin(), srt.end()), srt.end());
	for(int i = 1; i <= N; ++i){
		a[i] = lower_bound(srt.begin(), srt.end(), a[i]) - srt.begin() + 1;
		col[a[i]].push_back(i);
	}
	for(int i = 1; i < N; ++i){
		int x, y; cin >> x >> y;
		way[x].push_back(y), way[y].push_back(x);
	}
	dfs(1, -1, 1);
	for(int i = 1; i <= N; ++i){
		if(!(int)col[i].size()){
			break;
		}
		top[i] = col[i][0];
		for(int j = 1; j < (int)col[i].size(); ++j){
			int val = min(dep[top[i]], dep[col[i][j]]);
			top[i] = getlca(up(top[i], val), up(col[i][j], val));
		}
	}
	sol(1, -1);
	Dfs(1, -1);
	int ans = 0;
	for(int i = 1; i <= N; ++i){
		ans += !no[i];
	}
	cout << ans;
	return 0;
}