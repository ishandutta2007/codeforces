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

int n, k, m, a, b, sum;

vector <int> va, vb;

 int main() {
	ios_base::sync_with_stdio(false);
	cin >> a>> b;
	int nr = 1;
	
	while(sum + nr <= a + b)
		sum += nr++;

	for(int i = nr - 1; i > 0; i--) {
		if(a >= i) va.push_back(i), a -= i;
		else vb.push_back(i), b -= i;
	}
	cout << va << '\n' << vb;
}