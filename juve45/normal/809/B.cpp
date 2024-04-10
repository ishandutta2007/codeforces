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

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
	return out << '(' << p.st << ' ' << p.nd << ')';  
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;

	int l = 1, r = n;
	while(l != r) {
		int mid1 = (l + r) / 2;
		int mid2 = mid1 + 1;
		cout << "1 " << mid1 << ' ' << mid2 << endl;
		cin >> s;
		if(s == "TAK") r = mid1;
		else l = mid2;
	}

	int p1 = l;

	l = p1 + 1;
	r = n;

	while(l < r) {
		int mid1 = (l + r) / 2;
		int mid2 = mid1 + 1;
		cout << "1 " << mid2 << ' ' << mid1 << endl;
		cin >> s;
		if(s == "TAK") 	l = mid2;
		else 						r = mid1;
	}

	int ok = 1;
	if(p1 != l && l <= n) {
		cout << "1 " << l << ' ' << p1 << endl;
		cin >> s;
		if(s != "TAK")
			ok = 0;
	} else ok = 0;

	if(ok)
		return cout << "2 " << p1 << ' ' << l << endl, 0;


	l = 1;
	r = p1 - 1;

	while(l < r) {
		int mid1 = (l + r - 1) / 2;
		int mid2 = mid1 + 1;
		cout << "1 " << mid1 << ' ' << mid2 << endl;
		cin >> s;
		if(s == "TAK") 	r = mid1;
		else 						l = mid2;
	}
	
	if(p1 == l)
		return 1;

	return cout << "2 " << p1 << ' ' << l << endl, 0;

}