#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 7
#define DIM2 10007
#define MODULO 1000000007  
#define MAXN 1000000
#define BigNumSize 250
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
ll t,n,m,k,A[107];
int main() {

	schnell;
	cin >> t;
	forn(e, t) {
		cin >> n >> m >> k;
		forn(i, n) {
			cin >> A[i];
		}
		ll flag = 0;
		forn(i, n - 1) {
			if (abs(A[i] - A[i + 1]) <= k) {
				
				ll mi = max(ll(0), A[i + 1] - k);
				m += A[i] - mi;
				
			}
			else if (abs(A[i]-A[i+1])>k){
				if (A[i] > A[i + 1]) {
					ll mi = max(ll(0), A[i + 1] - k);
					m += A[i] - mi;
				}
				else {
					ll dif = A[i + 1] - k;
					if (A[i] + m < dif) {
						cout << "NO" << endl;
						flag = 1;
						break;
					}
					else {
						m -= dif - A[i];
					}
				}
			}
		}
		if (flag == 0) {
			cout << "YES" << endl;
		}
	}
	return 0;
}