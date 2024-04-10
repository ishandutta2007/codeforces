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

int va[] = {1, 1, 1, 3, 2, 1, 2, 3};
int vb[] = {3, 1, 3, 2, 3, 3, 3, 4};
string s;
int nra, nrb;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> s;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '1') {
			cout << va[nra] << ' ' << va[nra + 1];
			nra += 2;
			nra %= 8;
		} else {
			cout << vb[nrb] << ' ' << vb[nrb + 1];
			nrb += 2;
			nrb %= 8;
		}
		cout << '\n';
	}
}