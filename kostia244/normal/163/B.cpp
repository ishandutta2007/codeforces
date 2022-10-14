#include<bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
using ll = long long;
const int maxn = 101;
int k, n, h;
vector<array<int, 3>> a;
vector<int> can(long double t) {
	auto b = a;
	vector<int> ans;
	//for(auto &i : b) cout << i[1]*t/h << " "; cout << endl;
	for(int i = 1; i <= k; i++) {
		while(!b.empty() && floor(b.back()[1]*t/h + 1e-18) < i) b.pop_back();
		if(b.empty()) return {};
		ans.push_back(b.back()[2]);
		b.pop_back();
	}
	//cerr << t << " good\n";
	return ans;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k >> h;
	a = vector<array<int, 3>> (n);
	int tmp = 1;
	for(auto &i : a) cin >> i[0], i[2] = tmp++;
	for(auto &i : a) cin >> i[1];//, i[1] *= -1;//, cout << i[1] << endl;
	sort(all(a));
	reverse(all(a));
	//for(auto &i : a) i[1] *= -1;
	//cout << can(20./3).size() << endl;
	//return 0;
	long double l = 0, r = 1e9;
	for(int I = 0; I < 90; I++) {
		long double mid = l + (r-l)/2;
		if(can(mid).empty()) l = mid;
		else r = mid;
	}
	for(auto &i : can(r)) cout << i << " ";
}