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
		int n, m, rx, cx, ry, cy;
		cin >> n >> m >> rx >> cx >> ry >> cy;
		rx--; cx--; ry--; cy--;
		for(int i = 0; ; i++){
			if(norm(rx, n) == ry % n || norm(cx, m) == cy % m){
				cout << i << "\n";
				break;
			}
			rx++;
			cx++;
		}
	}
}