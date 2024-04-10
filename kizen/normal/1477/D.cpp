
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		vector<vector<int>> way(n);
		vector<pair<int, int>> lst;
		for(int i = 0; i < m; ++i){
			int x, y; cin >> x >> y; --x; --y;
			lst.push_back({x + 1, y + 1});
			way[x].push_back(y), way[y].push_back(x);
		}
		set<int> st;
		for(int i = 0; i < n; ++i){
			st.insert(i);
			sort(way[i].begin(), way[i].end());
		}
		vector<vector<int>> tree(n);
		vector<set<int>> star(n);
		vector<int> spos(n, -1);
		for(int i = 0; i < n; ++i){
			if(st.find(i) == st.end()){
				continue;
			}
			st.erase(i);
			auto dfs = [&](auto self, int x, int from)->void{
				int j = 0;
				if(spos[x] == -1){
					spos[x] = x;
				}
				if(spos[from] == from){
					star[from].insert(x), spos[x] = from;
				}
				for(auto p = st.begin(); p != st.end();){
					while(j < (int)way[x].size() && way[x][j] < *p){
						++j;
					}
					if(j < (int)way[x].size() && *p == way[x][j]){
						++p;
						continue;
					}
					tree[x].push_back(*p);
					if(spos[x] == x){
						star[x].insert(*p); spos[*p] = x;
					}
					st.erase(p++);
				}
				if(spos[x] == x && (int)tree[x].size() == 0){
					int nxt = from;
					if(nxt != -1){
						if((int)star[spos[nxt]].size() >= 2){
							star[spos[nxt]].erase(nxt);
							star[x].insert(nxt); spos[nxt] = x;
						}
						else{
							star[spos[nxt]].clear();
							star[nxt].insert(spos[nxt]), star[nxt].insert(x);
							spos[spos[nxt]] = spos[x] = nxt;
							spos[nxt] = nxt;
						}
					}
				}
				for(auto nxt:tree[x]){
					self(self, nxt, x);
				}
			};
			dfs(dfs, i, -1);
		}
		vector<int> a(n), b(n);
		int now = 1;
		for(int i = 0; i < n; ++i){
			if(spos[i] == i){
				int l = now, r = (int)star[i].size() + now;
				a[i] = l, b[i] = r;
				for(auto&nxt:star[i]){
					b[nxt] = l, a[nxt] = ++l;
				}
				now = r + 1;
			}
		}
		for(int i = 0; i < n; ++i){
			cout << a[i] << ' ';
		}
		cout << '\n';
		for(int i = 0; i < n; ++i){
			cout << b[i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}