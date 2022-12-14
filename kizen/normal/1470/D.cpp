#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while(T--){
		int N, M;
		cin >> N >> M;
		vector<vector<int>> way(N);
		for(int i = 0; i < M; ++i){
			int a, b; cin >> a >> b; --a, --b;
			way[a].push_back(b), way[b].push_back(a);
		}
		vector<int> chk(N), col(N), near(N);
		auto mone = [&](int x){
			col[x] = near[x] = 1;
			for(auto&nxt:way[x]){
				near[nxt] = 1;
			}
		};
		function<void(int)> dfs = [&](int x){
			chk[x] = 1;
			for(auto&nxt:way[x]){
				if(chk[nxt]){
					continue;
				}
				if(!col[x] && !near[nxt]){
					mone(nxt);
				}
				dfs(nxt);
			}
		};
		mone(0);
		dfs(0);
		int f = 0;
		vector<int> ans;
		for(int i = 0; i < N; ++i){
			if(!chk[i]){
				f = 1;
			}
			if(col[i]){
				ans.push_back(i + 1);
			}
		}
		if(f){
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		cout << (int)ans.size() << '\n';
		for(auto&i:ans){
			cout << i << ' ';
		}
		cout << '\n';
	}
	return 0;
}