#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using llf = long double;
using pi = pair<lint, lint>;
const int MAXN = 2005;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int q; cin >> q;
	while(q--){
		int n, k; cin >> n >> k;
		if((n + 1) / 2 < k){
			cout << "-1\n";
			continue;
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(i == j && i % 2 == 0 && i < k * 2) cout << 'R';
				else cout << '.';
			}
			cout << "\n";
		}
	}
}