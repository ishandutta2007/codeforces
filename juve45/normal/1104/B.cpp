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

int n, k, m, nr;
string s, t;
int main() {
	ios_base::sync_with_stdio(false);
	cin >> s;
	for(auto i : s)
		if(t.empty() || t.back() != i)
			t += i;
		else 
			t.pop_back(), nr++;

	if(nr % 2 == 0)
		cout << "No";
	else cout << "Yes";
}