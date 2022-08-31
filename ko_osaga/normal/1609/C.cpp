#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using llf = long double;
using pi = pair<lint, lint>;
const int MAXN = 1000005;

bool che[MAXN];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for(int i = 2; i * i < MAXN; i++){
		if(che[i]) continue;
		for(int j = i * i; j < MAXN; j += i){
			che[j] = 1;
		}
	}
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		vector<int> a(n);
		vector<int> cnt(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
			cnt[i] = 2;
			if(che[a[i]] == 0) cnt[i] = 1;
			if(a[i] == 1) cnt[i] = 0;
		}
		lint ret = 0;
		for(int i = 0; i < m; i++){
			vector<int> v = {0};
			int sum = 0;
			for(int j = i; j < n; j += m){
				sum += cnt[j];
				v.push_back(sum);
			}
			int j = 0;
			for(int i = 0; i + 1< sz(v); i++){
				while(j < sz(v) && v[j] - v[i] <= 1) j++;
				ret += max(0, j - i - 2);
			}
		}
		for(int i = 0; i < m; i++){
			vector<int> v = {0};
			int sum = 0;
			for(int j = i; j < n; j += m){
				sum += cnt[j];
				v.push_back(sum);
			}

			int j = 0;
			for(int i = 0; i + 1< sz(v); i++){
				while(j < sz(v) && v[j] - v[i] < 1) j++;
				ret -= max(0, j - i - 2);
			}
		}
		cout << ret << '\n';
	}
}