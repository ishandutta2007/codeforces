#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

int n, k;
string s, ans, ans2;

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

void que(int x, int y, int z, int t) {
	cout << "? " << x << ' ' << y << ' ' << z <<  ' ' << t << endl;
}

stack <pair<int, int> > state;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	int x = 1, y = 1;
	state.push({x, y});

	for(int i = 1; i < n; i++) {
		que(x + 1, y, n, n);
		cin >> s;
		if(s == "YES") {
			x++;
			ans += "D";
		} else {
			y++;
			ans += "R";
		}
		state.push({x, y});
	}
	state.pop();

	// dbg(ans);
	x = n, y = n;
	for(int i = 1; i < n; i++) {
		auto pp = state.top();
		state.pop();
		que(pp.st, pp.nd, x, y - 1);
		cin >> s;
		if(s == "YES") {
			ans2 += 'R';
			y--;
		} else {
			x--;
			ans2 += 'D';
		}
	}
	reverse(ans2.begin(), ans2.end());
	ans += ans2;
	cout << "! " << ans << endl;
}