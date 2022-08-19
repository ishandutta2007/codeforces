#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 1000005;
const int mod = 1e9 + 7;

lint a[30][30];

int main(){
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(j % 2 == 0){
				a[i][j] = (1ll << (i + j));
			}
			printf("%lld ", a[i][j]);
		}
		cout << endl;
	}
		cout << endl;
	int q; cin >> q;
	while(q--){
		lint k; cin >> k;
		vector<pi> v;
		v.emplace_back(0, 0);
		k -= 1;
		for(int i=1; i<2*n-1; i++){
			int x, y; tie(x, y) = v.back();
			if((k >> i) & 1){
				if(a[x + 1][y]) x++;
				else y++;
			}
			else{
				if((x + 1 < n && a[x+1][y] == 0)) x++;
				else y++;
			}
			v.emplace_back(x, y);
		}
		for(auto &[x, y] : v){
			printf("%d %d", x+1, y+1);
			cout << endl;
		}
		cout << endl;
	}
}