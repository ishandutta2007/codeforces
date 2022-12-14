#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k; cin >> n >> k;
	vector<vector<int>> way(n);
	vector<int> dep(n), par(n);
	for(int i = 0; i < n - 1; ++i){
		int x, y; cin >> x >> y; --x, --y;
		way[x].push_back(y), way[y].push_back(x);
	}
	int ocnt = 0;
	for(int i = 0; i < n; ++i){
		if((int)way[i].size() == 1) ++ocnt;
	}
	if(k >= n / 2 && k >= ocnt){
		cout << n / 2 * (n - n / 2) << '\n';
		return 0;
	}
	if(k >= ocnt){
		cout << k * (n - k) << '\n';
		return 0;
	}
	auto srt = [&](auto&&self, int x, int pr)->void{
		par[x] = pr;
		int f = 1, pos;
		for(int i = 0; i < (int)way[x].size(); ++i){
			int nxt = way[x][i];
			if(nxt != pr){
				f = 0;
				self(self, nxt, x);
				if(dep[nxt] >= dep[x]){
					dep[x] = dep[nxt] + 1, pos = i;
				}
			}
		}
		if(f) return;
		swap(way[x][0], way[x][pos]);
	};
	srt(srt, 0, -1);
	priority_queue<pair<int, int>> pq;
	pq.push({dep[0], 0});
	int sum = 0;
	auto go = [&](auto&&self, int x, int did)->void{
		if(did){
			pq.push({dep[x], x});
			return;
		}
		for(int i = 0; i < (int)way[x].size(); ++i){
			int nxt = way[x][i];
			if(nxt != par[x]){
				if(!i){
					self(self, nxt, 0);
				}
				else{
					self(self, nxt, 1);
				}
			}
		}
	};
	for(int i = 0; i < k; ++i){
		auto top = pq.top(); pq.pop();
		sum += top.first + 1;
		go(go, top.second, 0);
	}
	int bcu = n - sum;
	if(bcu >= n / 2){
		cout << (n - k - n / 2) * (k - n / 2) << '\n';
	}
	else{
		cout << (n - k - bcu) * (k - bcu) << '\n';
	}
	return 0;
}