#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using llf = long double;
using pi = pair<lint, lint>;
const int MAXN = 305;

int main(){
	int tc; cin >> tc;
	while(tc--){
		int n; cin >> n;
		vector<lint> a(n);
		int cnt = 0;
		for(auto &i : a){
			cin >> i;
			while(i % 2 == 0){
				i /= 2;
				cnt++;
			}
		}
		sort(all(a));
		a[n - 1] <<= cnt;
		cout << accumulate(all(a), 0ll) << '\n';
	}
}