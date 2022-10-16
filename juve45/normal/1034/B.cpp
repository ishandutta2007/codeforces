#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

long long n, k, pr[8][8];

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

void pre() {
	pr[1][0] = 0;
	pr[1][1] = 0;
	pr[1][2] = 0;
	pr[1][3] = 0;
	pr[1][4] = 1;
	pr[1][5] = 2;
	pr[1][6] = 3;
	pr[1][7] = 3;

	pr[2][3] = 2;
	pr[2][4] = 4;
	pr[2][5] = 5;
	pr[2][6] = 6;
	pr[2][7] = 6;

	pr[3][3] = 4;
	pr[3][4] = 6;
	pr[3][5] = 7;
	pr[3][6] = 9;
	pr[3][7] = 10; //!!!

	pr[4][4] = 8;
	pr[4][5] = 10;
	pr[4][6] = 12;
	pr[4][7] = 14;


	pr[5][5] = 12;
	pr[5][6] = 15;
	pr[5][7] = 17; //!!!

	pr[6][6] = 18;
	pr[6][7] = 21;

	pr[7][7] = 24;
}

int main() {
	ios_base::sync_with_stdio(false);
	long long n, m;
	pre();
	cin >> n >> m;
	if(n > m)
		swap(n, m);

	long long ans;
	if(m <= 2)
		ans = 0;
	else if(n == 1 && m < 4) 
		ans = 0;
	else if(n % 2 == 0) {
		if(n == 2 && m < 8) ans = 2 * pr[n][m];
		else ans = n * m;
	} else {
		if(n == 1) {
			long long nr = m / 6;
			long long off = m % 6;
			cout << nr * 6 + 2 * pr[1][off] << '\n';
			return 0;
		}
		if(m % 2 == 0)
			ans = n * m;
		else
			ans	= n * m - 1;
	}
	cout << ans << '\n';
}