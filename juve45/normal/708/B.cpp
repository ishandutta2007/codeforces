#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

long long n, k, n1, n0, a0, a1, a10, a01;

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
	cin >> a0 >> a01 >> a10 >> a1;

	if(a0 >= 1)
		n0 = (long long)(sqrt(2 * a0)) + 1;
	else if(a01 || a10)
		n0 = 1;
	if(a1 >= 1)
		n1 = (long long)(sqrt(2 * a1)) + 1;
	else if(a01 || a10)
		n1 = 1;

	if(n0 * (n0 - 1) != 2 * a0)
		return cout << "Impossible\n", 0;
	if(n1 * (n1 - 1) != 2 * a1)
		return cout << "Impossible\n", 0;
	if(n0 * n1 != a01 + a10) {
		cout << "Impossible\n";
		return 0;
	}

	//00000111111
	if(n1 == 0) {
		if(n0 == 0) n0++;
		cout << string(n0, '0');
		return 0;
	}

	long long tot = n0 * n1;
	long long dif = tot - a01;
	long long nrfinal = dif / n1;
	long long nrinter = dif % n1;

	//000...00111...11011...11100000
	if(nrinter == 0) {
		cout << string(n0 - nrfinal, '0');
		cout << string(n1, '1');
		cout << string(nrfinal, '0');
	} else {
		cout << string(n0 - nrfinal - 1, '0');
		cout << string(nrinter, '1');
		cout << '0';
		cout << string(n1-nrinter, '1');
		cout << string(nrfinal, '0');
	}


}