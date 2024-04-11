#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<lint, lint>;

int norm(int x, int d){
	if(d == 1) return 0;
	x %= (2 * d - 2);
	if(x >= d) return 2 * d - 2 - x;
	return x;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int q; cin >> q;
	while(q--){
		int n; cin >> n;
		vector<pi> a(n);
		for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
		sort(all(a), [&](const pi &p, const pi &q){
			return p.second - p.first < q.second - q.first;
		});
		vector<int> chk(n + 1);
		for(int i = 0; i < n; i++){
			for(int j = a[i].first; j <= a[i].second; j++){
				if(!chk[j]){
					cout << a[i].first << " " << a[i].second << " " << j << "\n";
					chk[j] = 1;
				}
			}
		}
		cout << "\n";
	}
}