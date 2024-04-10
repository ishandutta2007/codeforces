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
struct node {
	ll l, r, end, val;
	bool operator < (const node& b)const {
		return val < b.val;
	}
	bool operator > (const node& b)const {
		return val > b.val;
	}
};
bool mc(node a, node b) {
	return a.l < b.l;
}
ll h, l;
int main() {
	schnell;
	cin >> h >> l;
	ld x = ld(l * l + h * h) / (2 * h);
	cout <<fixed<<setprecision(10)<< x-h << endl;

	return 0;
}