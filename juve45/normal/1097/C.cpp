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

const int N = 500100;
int n, k, m, l[N], r[N], ans;
string s;

void prel(string & s) {
	int sum = 0, mn = 1;
	
	// dbg(s);

	for(auto c : s) {
		if(c == '(') sum++;
		else sum--;
		mn = min(sum, mn);
	}
	
	// dbg(mn);
	// dbg(sum);

	if(mn < 0 && mn != sum) return;
	
	if(sum < 0) l[-sum]++;
	else r[sum]++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> s;
		prel(s);
	}

	dbg_v(r, 10);
	dbg_v(l, 10);

	ans += r[0] / 2;
	for(int i = 1; i <= 500000; i++)
		ans += min(l[i], r[i]);
	cout << ans << '\n';
}