#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 200007
#define DIM2 10007
#define MODULO 998244353  
#define MAXN 1000000
#define DIM2 31
const long long INF = 10E16;
const ll mask = po(9) - 1;
const ll base = 100000000000;
struct pp {
	ll fi, sc;
	bool operator < (const pp& b)const {
		if (fi == b.fi)return sc < b.sc;
		return fi < b.fi;
	}
	bool operator > (const pp& b)const {
		if (fi == b.fi)return sc > b.sc;
		return fi > b.fi;
	}
	bool operator == (const pp& b)const {
		if (fi == b.fi && sc == b.sc)return 1;
		return 0;
	}
};
ll n,k,A[DIM];
int main() {
	schnell;
	cin >> n>>k;
	forn(i, n)cin >> A[i];
	sort(A + 1, A + 1 + n);
	ll tm = n / 2 + 1,pos = tm,r = 1;
	while (k > 0) {
		while (pos < n && A[pos+1] == A[tm]) {
			r++; pos++;
		}
		if (pos == n && k > 0) {
			A[tm] += k / r;
			break;
		}
		if (pos == n && k == 0)break;
		if ((A[pos+1] - A[tm])*r <= k) {
			k -= (A[pos+1] - A[tm])*r;
			A[tm] = A[pos+1];
			r++;
			pos++;
		}
		else {
			A[tm] += k/r;
			break;
		}
	}
	cout << A[tm] << endl;
	return 0;
}