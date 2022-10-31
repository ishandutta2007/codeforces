#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long  ll;
typedef long double ld;
#define DIM 100007
#define DIM2 10007
#define MODULO 998244353 
#define MAXN 1000000
#define DIM2 31
const long long INF = 10E16;
const ll mask = po(9) - 1;
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
ll n, m, k,A[DIM],S[DIM];
int main() {
	schnell;
	cin >> n >> m >> k;
	forn(i, n) {
		cin >> A[i];
		if (i == 1)S[i] = INF;
		else {
			S[i]= A[i] - A[i - 1];
		}

	}
	ll res = n,num = n,pos = 1;
	sort(S + 1, S + 1 + n);
	while (num > k) {
		num--;
		res += S[pos] - 1;
		pos++;
	}
	cout << res << endl;
	return 0;
}