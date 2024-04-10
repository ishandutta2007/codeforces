#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 100100;
int n, k, m, a[N], b[N];

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

int sch(int l, int r) {
	if(l == r)
		return l;
	int mid = (l + r) / 2;

	cout << "? " << mid << endl;
	cin >> a[mid];
	cout << "? " << n/2 + mid << endl;
	cin >> a[n / 2 + mid];

	b[mid] = a[mid] - a[mid + n / 2];
	if(b[mid] == 0)
		return mid;

	if(b[mid] * b[r] < 0)
		return sch(mid, r);
	return sch(l, mid);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;

	if((n / 2) % 2 != 0) {
		cout << "! -1" << endl;
		return 0;
	}

	cout << "? " << 1 << endl;
	cin >> a[1];
	cout << "? " << n/2 + 1 << endl;
	cin >> a[n / 2 + 1];
	b[1] = a[1] - a[n / 2 + 1];
	b[n / 2 + 1] = -a[1] + a[n / 2 + 1];

	if(b[1] == 0) 
		return cout << "! 1" << endl, 0;


	int ans = sch(1, n / 2 + 1);
	cout << "! " << ans << endl;
}