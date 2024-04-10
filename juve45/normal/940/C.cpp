#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

int n, k;
string s, t;
set<char> chr;

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
	cin >> n >> k;
	cin >> s;
	
	char mn = 'z';
	char mx = 'a';
	
	for(auto i : s) {
		mn = min(i, mn);
		mx = max(i, mx);
		chr.insert(i);
	}

	if(k > n)
		cout << s + string(k - n, mn) << '\n';
	else {
		t = s.substr(0, k);
		for(int i = (int)t.size() - 1; i >= 0; i--)
			if(t[i] != mx) {
				// dbg(*chr.upper_bound(t[i]));
				t[i] = *chr.upper_bound(t[i]);
				for(int j = i + 1; j < t.size(); j++)
					t[j] = mn;
				break;
			}
		cout << t << '\n';
	}
}