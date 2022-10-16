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

pair<pair<int, int> , int > a[300100];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].st.st >> a[i].st.nd;
		a[i].st.nd = -a[i].st.nd;
		a[i].nd = i;
	}

	sort(a + 1, a + n + 1);
	int e = -1e9, ind = -1;
	for(int i = 1; i <= n; i++) {
		if(-a[i].st.nd > e) e = -a[i].st.nd, ind = a[i].nd;
		else {
			cout << a[i].nd << ' ' << ind << '\n';
			return 0;
		}
	}
	cout << "-1 -1\n";
}