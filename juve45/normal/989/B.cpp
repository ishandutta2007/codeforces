#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 111;
int n, k, p;
string s;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> p;
	cin >> s;

	int ok = 0;

	for(int i = 0; i + p < n; i++) {
		if(s[i] != s[i + p]) {

			if(s[i] == '.') {
				if(s[i + p] == '1')
					s[i] = '0';
				else 
					s[i] = '1';
			} else if(s[i + p] == '.') {
				if(s[i] == '1')
					s[i + p] = '0';
				else 
					s[i + p] = '1';
			}
			ok = 1;
		} else if(s[i] == '.' && s[i + p] == '.') {
			s[i] = '1';
			s[i + p] = '0';
			ok = 1;
		}
	}

	for(int i = 0; i < n; i++)
		if(s[i] == '.')
			s[i] = '0';

	if(ok) {
		cout << s << '\n';
	} else cout << "No\n";
}