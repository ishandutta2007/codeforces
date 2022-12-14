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
		int n; cin >> n;
		string s; cin >> s;
		int zo = 0;
		for(int i = 0; i < n; ++i){
			if(s[i] == '1'){
				++zo;
			}
		}
		if(zo % 2 || !zo){
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		int i = 0;
		while(s[i] == '0') ++i;
		int j = i;
		vector<int> ed;
		int mcnt = 0;
		while(mcnt < n){
			int x = j;
			while(s[(x + 1) % n] != '1'){
				cout << x + 1 << ' ' << (x + 1) % n + 1 << '\n';
				x = (x + 1) % n; ++mcnt;
			}
			ed.push_back(x);
			j = (x + 1) % n; ++mcnt;
		}
		for(int i = 1; i < (int)ed.size(); ++i){
			cout << ed[0] + 1 << ' ' << ed[i] + 1 << '\n';
		}
	}
	return 0;
}