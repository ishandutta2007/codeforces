 #include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

int n, k;
string s;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int is(string s) {
	string t = s;
	reverse(t.begin(), t.end());
	return (t == s);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> s;
	int n = s.size();
	while(n) {
		if(!is(s.substr(0, n))) {
			cout << n << '\n';
			return 0;
		}
		n--;
	}
	cout << 0 << '\n';
}