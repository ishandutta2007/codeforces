#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define DMAX 300100
#define NMAX 
#define MMAX 

using namespace std;

int n, k, c1, c2, x1, x2, a;
pair<int, int> c[DMAX];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

bool solve(int x1, int x2) {
	
	set<int> ans;
	// pun pe x1 la sfarsit
	for(int i = 1; i <= n; i++)
		if(c[n - i + 1].first >= (x1 + i - 1) / i)
			ans.insert(n - i + 1);

	// for(auto i : ans ) dbg(i);

	//pun pe x2 la inceput
	for(int i = 1; i <= n; i++) {
		int val = (x2 + i - 1) / i;
		int pos = lower_bound(c + 1, c + n + 1, make_pair(val, -1)) - c;
		pos += i - 1;
		if(ans.upper_bound(pos) != ans.end()){
			c1 = n - *ans.upper_bound(pos) + 1;
			c2 = i;
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> x1 >> x2;
	for(int i = 1; i <= n; i++) cin >> a, c[i] = {a, i};

	sort(c + 1, c + n + 1);
	// dbg_v(c, n + 1);
	if(solve(x1, x2)) {
		cout << "Yes\n";
		cout << c1 << ' ' << c2 << '\n';
		for(int i = n; i > n - c1; i--)
			cout << c[i].nd << ' ';
		cout << '\n';

		for(int i = n - c1; i > n - c1 - c2; i--)
			cout << c[i].nd << ' ';
		cout << '\n';
		return 0;
	}
	if(solve(x2, x1)) {
		cout << "Yes\n";
		cout << c2 << ' ' << c1 << '\n';
		
		for(int i = n - c1; i > n - c1 - c2; i--)
			cout << c[i].nd << ' ';
		cout << '\n';
		
		for(int i = n; i > n - c1; i--)
			cout << c[i].nd << ' ';
		cout << '\n';


		return 0;
	}
	cout << "No\n";
}