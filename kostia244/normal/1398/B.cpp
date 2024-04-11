//#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 3e5 + 33, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		string s;cin >> s;
		s+='0';
		vector<int> a;
		int c = 0;
		for(auto &i : s) {
			if(i == '1') c++;
			else a.push_back(c), c = 0;
		}
		sort(rall(a));
		int ans = 0;
		for(int i = 0; i < a.size(); i+=2) ans += a[i];
		cout << ans << '\n';
	}
}