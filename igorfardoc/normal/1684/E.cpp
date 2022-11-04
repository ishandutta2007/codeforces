#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		vi a(n);
		for(int i = 0; i < n; i++) {
			 cin >> a[i];
		}
		vi am(n, 0);
		map<int, int> am1;
		for(int i = 0; i < n; i++) {
			if(a[i] < n) {
				++am[a[i]];
			} else {
				++am1[a[i]];
			}
		}
		multiset<int> fir;
		for(const auto& el : am1) {
			fir.insert(el.second);
		}
		for(int i = 0; i < n; i++) {
			if(am[i] > 0) {
				fir.insert(am[i]);
			}
		}
		multiset<int> sec;
		int ans = fir.size();
		int need = 0;
		int secam = 0;
		for(int i = 0; i < n; i++) {
			if(am[i] == 0) {
				++need;
			} else {
				auto it = sec.find(am[i]);
				if(it != sec.end()) {
					sec.erase(it);
					secam -= am[i];
				} else {
					fir.erase(fir.find(am[i]));
				}
			}
			if(need > k) break;
			while(!fir.empty() && secam + *(fir.begin()) <= k) {
				secam += *(fir.begin());
				sec.insert(*(fir.begin()));
				fir.erase(fir.begin());
			}
			ans = min(ans, (int)fir.size());
		}
		cout << ans << '\n';
	}

}