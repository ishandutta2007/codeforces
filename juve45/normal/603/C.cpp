#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

int n, k, x;

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

int sg[] = {0, 1, 0, 1, 2, 0, 2};

int get_sg(int k) {
	if(k < 7) 
		return sg[k];
	if(k % 2 == 1)
		return 0;
	int nr = get_sg(k / 2);
	if(nr == 0)
		return 1;
	if(nr == 1)
		return 2;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;

	int ans = 0;
	for(int i = 1; i <= n; i++) {
		cin >> x;
		if(k % 2 == 0) {
			if(x % 2 == 0) {
				if(x == 2 || x == 0)
					ans ^= x;
				else 
					ans ^= 1;
			}
			else if(x == 1)
				ans ^= 1;
		} else 
			ans ^= get_sg(x);
	}
	dbg(get_sg(8));
	cout << (ans == 0 ? "Nicky" : "Kevin") << '\n';

}