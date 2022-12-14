#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		vector<pair<int, int>> way(m);
		for(int i = 0; i < m; ++i){
			cin >> way[i].first >> way[i].second;
		}
		vector<int> eans, chk(n * 3 + 1, 1);
		for(int i = 0; i < m; ++i){
			if(chk[way[i].first] && chk[way[i].second]){
				chk[way[i].first] = chk[way[i].second] = 0;
				eans.push_back(i + 1);
			}
		}
		if((int)eans.size() >= n){
			cout << "Matching\n";
			for(int i = 0; i < n; ++i){
				cout << eans[i] << ' ';
			}
			cout << '\n';
		}
		else{
			cout << "IndSet\n";
			int ocnt = n;
			for(int i = 1; i <= n * 3; ++i){
				if(chk[i] && ocnt){
					--ocnt;
					cout << i << ' ';
				}
			}
			cout << '\n';
		}
	}
	return 0;
}