#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<lint, lint> pi;
const int mod = 1e9 + 7;
const int MAXN = 100005;

vector<int> v[2][MAXN];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m; cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int x; cin >> x;
			v[0][x].push_back(i);
			v[1][x].push_back(j);
		}
	}
	lint ret = 0;
	for(int j = 0; j < 2; j++){
		for(int i = 1; i <= 100000; i++){
			sort(all(v[j][i]));
			vector<int> w = v[j][i];
			for(int i = 1; i < sz(w); i++){
				ret += 1ll * (w[i] - w[i-1]) * i * (sz(w) - i);
			}
		}
	}
	cout << ret << "\n";
}