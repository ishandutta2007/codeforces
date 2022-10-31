#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long  ll;
typedef long double ld;
#define DIM 2007
#define DIM2 10007
#define MODULO 1000000007  
#define MAXN 1000000
#define MS 302
#define BigNumSize 250
#define AddLimit 151
const long long INF = 10E16;
const ll mask = po(9) - 1;
const ll base = 100000000000;
const ld eps = 0.0000001;
struct pp {
	ld fi, sc;
	bool const operator < (const pp& b) {
		if (fi == b.fi)return sc < b.sc;
		return fi < b.fi;
	}
	bool const operator > (const pp& b) {
		if (fi == b.fi)return sc > b.sc;
		return fi > b.fi;
	}
	bool const operator == (const pp& b) {
		if (fi == b.fi && sc == b.sc)return 1;
		return 0;
	}
};
ll n, q,A[207];
int main() {
	schnell;
	cin >> q;
	ll start;
	forn(e, q) {

		cin >> n;
		
		forn(i, n) {
			cin >> A[i];
			if (A[i] == 1)start = i;
		}
		if (n == 1) {
			cout << "YES" << endl;
			continue;
		}
		ll pos = start - 1, last = 1, flag = 0;
		if (pos < 1)pos = n;
		while (1) {
			if (A[pos] != last + 1) {
				flag++;
				break;
			}
			last++;
			pos--;
			if (pos < 1)pos = n;
			if (pos == start)break;
		}
		pos = start + 1, last = 1;
		if (pos > n)pos = 1;
		while (1) {
			if (A[pos] != last + 1) {
				flag++;
				break;
			}
			last++;
			pos++;
			if (pos > n)pos = 1;
			if (pos == start)break;
		}
		if (flag == 2) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}
	}
	return 0;
}