#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 100100;
int n, k, a[N];
string s;

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
	for(int i = 1; i <= n; i++)
		cin >> a[i];

	cin >> s;
	s = " " + s;
	int l = -1e9;
	int r = 1e9;
	for(int i = 5; i <= n; i++) {

		if(s[i] == '1' && s[i - 1] == '0') {
			for(int j = 0; j < 5; j++)
				l = max(l, a[i - j] + 1);
		} else if(s[i] == '0' && s[i - 1] == '1') {
			for(int j = 0; j < 5; j++)
				r = min(r, a[i - j] - 1);
		}
		
	}
	cout << l << ' ' << r << '\n';
	return 0;
}