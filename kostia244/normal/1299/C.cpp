#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<int>;
const int maxn = 1<<19, mlg = 18, rt = 1<<10, mod = 1e9 + 7;
using ld = long double;
using pi = pair<ll, ll>;
bool good(pi a, pi b) {
	return (a.first + b.first)*a.second < a.first*(a.second+b.second);
}
void merge(pi &a, pi b) {
	a.first += b.first, a.second += b.second;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	vector<pi> s;
	pi cur;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> cur.first;
		cur.second = 1;
		s.pb(cur);
		while(s.size() > 1) {
			cur = s.back();
			s.pop_back();
			if(good(s.back(), cur)) merge(s.back(), cur);
			else {
				s.pb(cur);
				break;
			}
		}
	}
	cout << fixed << setprecision(15);
	for(auto i : s) {
		ld avg = ld(i.first)/i.second;
		while(i.second--) cout << avg << "\n";
	}
}