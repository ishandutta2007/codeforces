#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	const int MAX = 10009;
	vector<vector<pii>> h(MAX), v(MAX);
	for(int i = 0; i < n; i ++){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1 += 5000, y1 += 5000, x2 += 5000, y2 += 5000;
		y1 == y2 ? h[y1].push_back({min(x1, x2), max(x1, x2)}) : v[x1].push_back({min(y1, y2), max(y1, y2)});
	}
	long long res = 0;
	for(int y = 0; y < MAX; y ++){
		for(auto hs: h[y]){
			vector<int> bit(MAX + 1);
			auto update = [&](int i, int val){
				for(i ++; i <= MAX; i += i & -i){
					bit[i] += val;
				}
			};
			auto cnt = [&](int i){
				int res = 0;
				for(i ++; i > 0; i -= i & -i){
					res += bit[i];
				}
				return res;
			};
			vector<vector<int>> vevent(MAX);
			for(int x = hs.first; x <= hs.second; x ++){
				for(auto vs: v[x]){
					if(vs.first <= y && vs.second > y){
						update(x, 1);
						vevent[vs.second].push_back(x);
					}
				}
			}
			for(int uy = y + 1; uy < MAX; uy ++){
				for(auto uhs: h[uy]){
					long long s = cnt(uhs.second) - cnt(uhs.first - 1);
					res += s * (s - 1) / 2;
				}
				for(auto x: vevent[uy]){
					update(x, -1);
				}
			}
		}
	}
	cout << res;
	return 0;
}