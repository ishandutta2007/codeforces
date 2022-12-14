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
		vector<vector<int>> way(N), wayb(N);
		for(int i = 0; i < M; ++i){
			int a, b;
			cin >> a >> b; --a, --b;
			way[a].push_back(b);
			wayb[b].push_back(a);
		}
		vector<int> dis(N);
		dis[0] = 0;
		vector<int> q(N * 2);
		int f = 0, r = 0;
		q[r++] = 0;
		while(f < r){
			for(auto&nxt:way[q[f]]){
				if(dis[nxt] || nxt == 0){
					continue;
				}
				dis[nxt] = dis[q[f]] + 1;
				q[r++] = nxt;
			}
			++f;
		}
		vector<int> mn(N);
		priority_queue<pair<int, int>> pq;
		vector<int> chk(N);
		for(int i = 0; i < N; ++i){
			mn[i] = dis[i];
			for(auto&nxt:way[i]){
				mn[i] = min(mn[i], dis[nxt]);
			}
			pq.push({-mn[i], i});
		}
		while(!pq.empty()){
			while(!pq.empty() && chk[pq.top().second]){
				pq.pop();
			}
			if(pq.empty()){
				break;
			}
			int top = pq.top().second; pq.pop();
			chk[top] = 1;
			for(auto&nxt:wayb[top]){
				if(dis[nxt] < dis[top]){
					if(mn[top] < mn[nxt]){
						mn[nxt] = mn[top];
						pq.push({-mn[nxt], nxt});
					}
				}
			}
		}
		for(int i = 0; i < N; ++i){
			cout << mn[i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}