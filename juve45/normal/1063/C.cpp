#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

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

int n, k, m;
string s;

vector <pair<int, char> > v;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	int offset = 0;
	int sgn = 1;

	n--;
	cout << "0 0" << endl;
	cin >> s;
	char f = s[0];
	v.push_back({0, f});
	while(n) {
		n--;
		offset += sgn * (1 << n);
		cout << 0 << ' ' << offset << endl;
		cin >> s;
		v.push_back({offset, s[0]});
		if(s[0] != f) sgn = -1;
		else sgn = 1;
	}


	sort(v.begin(), v.end());
	// dbg(v);
	v.push_back({1e9 - 2, 'x'});
	for(int i = 0; i < v.size() - 1; i++)
		if(v[i].nd != v[i + 1].nd) {
			cout << "1 " << v[i + 1].st << " 4 " << v[i + 1].st + 1 << endl;
			return 0;
		}
}