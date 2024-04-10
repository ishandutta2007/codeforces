#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

// #define cerr if(0)cout

#define st first
#define nd second

using namespace std;

const int N = 400100;
const int MOD = 1e9 + 7;
int n, k, m, p;
string s;

template<class T>
ostream& operator<<(ostream& out, set<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
	return out << '(' << p.st << ' ' << p.nd << ')';  
}

set<int> buy, sell, idk;
long long ans = 1;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> s >> p;
		if(s == "ACCEPT") {
			if(idk.count(p)) {
				ans *= 2;
				ans %= MOD;
				idk.erase(p);
				for(auto e : idk)
					if(e < p) buy.insert(e);
					else sell.insert(e);
				idk.clear();
			} else {
				if(!buy.empty() && p == *buy.rbegin()) {
					buy.erase(p);
					for(auto e : idk) sell.insert(e);
					idk.clear();
				} else if(!sell.empty() && p == *sell.begin()) {
					sell.erase(p);
					for(auto e : idk) buy.insert(e);
					idk.clear();
				} else {
					cout << "0\n";
					return 0;
				}
			}
		} else {
			if(!buy.empty() && *buy.rbegin() >= p)
				buy.insert(p);
			else if(!sell.empty() && *sell.begin() <= p)
				sell.insert(p);
			else {
				// if(!idk.empty() && p > *idk.begin() && p < *idk.rbegin()) {
				// 	for(auto e : idk)
				// 		if(e < p) buy.insert(e);
				// 		else sell.insert(e);
				// 	idk.clear();
				// }

				idk.insert(p);
			}
		}
		// dbg(idk);
		// dbg(buy);
		// dbg(sell);
	}
	if(idk.size() > 0)
		ans *= (idk.size() + 1);
	ans %= MOD;
	cout << ans << '\n';
}