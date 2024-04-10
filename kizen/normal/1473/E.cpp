#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long N, M;
	cin >> N >> M;
	vector<vector<pair<long long, long long>>> way(N);
	for(long long i = 0; i < M; ++i){
		long long a, b, c; cin >> a >> b >> c; --a, --b;
		way[a].push_back({b, c}), way[b].push_back({a, c});
	}
	priority_queue<pair<long long, vector<long long>>> pq;
	pq.push({0, {0, 1, 1}});
	vector<vector<long long>> chk(N, vector<long long>(4)), ans(N, vector<long long>(4));
	for(long long i = 1; i < N; ++i){
		for(long long j = 0; j < 4; ++j){
			ans[i][j] = (long long)1e18;
		}
	}
	ans[0][1] = ans[0][2] = ans[0][0] = (long long)1e18;
	while(!pq.empty()){
		if(chk[pq.top().second[0]][pq.top().second[1] * 2 + pq.top().second[2]]){
			pq.pop();
			continue;
		}
		auto top = pq.top().second; pq.pop();
		chk[top[0]][top[1] * 2 + top[2]] = 1;
		long long val = ans[top[0]][top[1] * 2 + top[2]];
		for(auto&nxt:way[top[0]]){
			if(val + nxt.second < ans[nxt.first][top[1] * 2 + top[2]]){
				ans[nxt.first][top[1] * 2 + top[2]] = val + nxt.second;
				pq.push({-ans[nxt.first][top[1] * 2 + top[2]], {nxt.first, top[1], top[2]}});
			}
			if(top[1]){
				if(val < ans[nxt.first][top[2]]){
					ans[nxt.first][top[2]] = val;
					pq.push({-ans[nxt.first][top[2]], {nxt.first, 0, top[2]}});
				}
			}
			if(top[2]){
				if(val + nxt.second * 2 < ans[nxt.first][top[1] * 2]){
					ans[nxt.first][top[1] * 2] = val + nxt.second * 2;
					pq.push({-ans[nxt.first][top[1] * 2], {nxt.first, top[1], 0}});
				}
			}
			if(top[1] && top[2]){
				if(val + nxt.second < ans[nxt.first][0]){
					ans[nxt.first][0] = val + nxt.second;
					pq.push({-ans[nxt.first][0], {nxt.first, 0, 0}});
				}
			}
		}
	}
	for(long long i = 1; i < N; ++i){
		cout << ans[i][0] << ' ';
	}
	return 0;
}