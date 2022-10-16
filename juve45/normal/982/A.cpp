#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define DMAX 
#define NMAX 
#define MMAX 

using namespace std;

int n, k;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int main() {
	ios_base::sync_with_stdio(false);
	string s;
	cin >> n;
	cin >> s;

	for(int i = 1; i + 1 < s.size(); i++) {
		if(s[i] == '1') {
			if(s[i - 1] == '1' || s[i + 1] == '1')
				return cout << "No\n", 0;
		}
		else 
			if(s[i - 1] == '0' && s[i + 1] == '0')
				return cout << "No\n", 0;
	}

	if(s.size() == 2 && s == "11") 
				return cout << "No\n", 0;
	if(s.size() == 1 && s == "0") 
				return cout << "No\n", 0;
	if(s.size() >= 2) {
		if(s[0] == '0' && s[1] == '0')
				return cout << "No\n", 0;
		if(s[s.size() - 2] == '0' && s[s.size() - 1] == '0')
				return cout << "No\n", 0;
	}
	cout << "Yes\n";
}