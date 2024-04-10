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

ll n, m, k, q, line[DIM][2], safe[DIM], D[DIM][2];
ll lo(ll x) {
	auto it = upper_bound(safe + 1, safe + 1 + q, x);
	ll pos = it - safe;
	pos--;
	if (pos > 0)return safe[pos];
	else return safe[pos+1];
}
ll up(ll x) {
	auto it = lower_bound(safe + 1, safe + 1 + q, x);
	ll pos = it - safe;
	if (pos <= q)return safe[pos];
	else return safe[pos - 1];
}
int main() {
	cin >> n >> m >> k >> q;
	for (ll i = 0; i < DIM; i++) {
		line[i][0] = INF;
		line[i][1] = -1;
	}
	ll end = -1;
	forn(i, k) {
		ll x, y;
		cin >> x >> y;
		line[x][0] = min(line[x][0], y);
		line[x][1] = max(line[x][1], y);
		end = max(end, x);	
	}
	
	forn(i, q)cin >> safe[i];
	sort(safe + 1, safe + 1 + q);
	if (line[1][1] == -1) {
		line[1][1] = 1;
		line[1][0] = 1;
	}	
	D[1][0] = line[1][1] - 1 + line[1][1] - line[1][0];
	D[1][1] = line[1][1] - 1;
	
	for (ll i = 2; i <= end; i++) {
		if (line[i][1] == -1) {
			line[i][1] = line[i - 1][1];
			line[i][0] = line[i - 1][0];
			D[i][0] = D[i - 1][0] + 1;
			D[i][1] = D[i - 1][1] + 1;
			continue;
		}
		D[i][0] = line[i][1] - line[i][0];
		D[i][1] = D[i][0];
		pp r = { lo(line[i][1]),up(line[i][1]) }, l = { lo(line[i][0]),up(line[i][0]) };
		ll m1, m2;
		m1 = D[i - 1][0] + 1 + min(abs(line[i - 1][0] - r.fi) + abs(r.fi - line[i][1]), abs(line[i - 1][0] - r.sc) + abs(r.sc - line[i][1]));
		m1 = min(m1, D[i - 1][1] + 1 + min(abs(line[i - 1][1] - r.fi) + abs(r.fi - line[i][1]), abs(line[i - 1][1] - r.sc) + abs(line[i][1] - r.sc)));
		m2 = D[i - 1][0] + 1 + min(abs(line[i - 1][0] - l.fi) + abs(l.fi - line[i][0]), abs(line[i - 1][0] - l.sc) + abs(l.sc - line[i][0]));
		m2 = min(m2, D[i - 1][1] + 1 + min(abs(line[i - 1][1] - l.fi) + abs(l.fi - line[i][0]), abs(line[i - 1][1] - l.sc) + abs(l.sc - line[i][0])));
		D[i][0] += m1;
		D[i][1] += m2;
	}
	cout << min(D[end][0], D[end][1]) << endl;
	return 0;
}