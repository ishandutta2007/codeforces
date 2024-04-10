#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#ifndef LOCAL
#define cerr if(0)cout
#endif

#define st first
#define nd second
#define y1 ty572
using namespace std;

const int N = 150100;
int n, k, x1[N], x2[N], y1[N], y2[N];

multiset<int> x1s, x2s, y1s, y2s;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
	return out << '(' << p.st << ' ' << p.nd << ')';  
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
		x1s.insert(x1[i]);
		y1s.insert(y1[i]);
		x2s.insert(x2[i]);
		y2s.insert(y2[i]);
	}

	for(int i = 1; i <= n; i++) {
		x1s.erase(x1s.find(x1[i]));
		y1s.erase(y1s.find(y1[i]));
		x2s.erase(x2s.find(x2[i]));
		y2s.erase(y2s.find(y2[i]));

		if(*x1s.rbegin() <= *x2s.begin() && *y1s.rbegin() <= *y2s.begin()) {
			cout << *x1s.rbegin() << ' ' << *y1s.rbegin() << '\n';
			return 0;
		}
		x1s.insert(x1[i]);
		y1s.insert(y1[i]);
		x2s.insert(x2[i]);
		y2s.insert(y2[i]);
	}

}