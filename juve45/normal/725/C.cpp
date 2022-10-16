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

int n, k, m, f[555];
char letter;
string s, ss[3];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> s;
	for(auto i : s)
		if(f[i]) {
			letter = i;
		}
		else f[i] = 1;

	int j = 0;
	for(auto i : s) {
		if(i == letter)
			j++;
		else ss[j] += i;
	}

	// cout << ss[0] << '\n';
	// cout << ss[1] << '\n';
	// cout << ss[2] << '\n';

	if(ss[1].size() == 0) {
		cout << "Impossible\n";
		return 0;
	}

	int sz = ss[1].size();
	sz = (sz + 1) / 2;
	string t1 = ss[1].substr(0, sz);
	string t2 = ss[1].substr(sz);
	reverse(ss[0].begin(), ss[0].end());
	reverse(ss[2].begin(), ss[2].end());
	string ans = t2 + letter + ss[0] + ss[2] + t1;
	cout << ans.substr(0, 13) << '\n';
	string tt = ans.substr(13);
	reverse(tt.begin(), tt.end());
	cout << tt << '\n';

}