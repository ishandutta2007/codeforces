#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef int ll;
typedef long double ld;
#define DIM 100007
#define DIM2 10007
#define MODULO 10000000000 
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
ll n,A[DIM],ans[2][DIM];
void co(ll p, ll start) {
	for (ll i = start; i >= 1; i--) {
		cout << ans[p][i];
	}
	cout << endl;
}
int main() {
	schnell;
	cin >> n;
	forn(i, n) {
		char x; cin >> x;
		A[i] = x - '0';
	}
	ll mid = n / 2;
	ll l = mid + 1, r = mid + 2;
	while (l >= 1 && A[l] == 0)l--;
	while (r <= n && A[r] == 0)r++;
	ll mod = 0;
	ll last[2];
	if (l > 0) {
		ll turn = 1;
		for(ll i = n;i>=l;i--){
			ans[mod][turn] += A[i];
			turn++;
		}
		turn = 1;
		for (ll i = l - 1; i >= 1; i--) {
			ans[mod][turn] += A[i];
			ans[mod][turn + 1] += ans[mod][turn] / 10;
			ans[mod][turn] %= 10;
			turn++;
		}
		
		for (ll i = 1; i <= n; i++) {
			ans[mod][i + 1] += ans[mod][i] / 10;
			ans[mod][i] %= 10;
			if (ans[mod][i] != 0)last[mod] = i;
		}
	}
	mod = 1;
	if (r <= n) {
		
			ll turn = 1;
			for (ll i = n; i >= r; i--) {
				ans[mod][turn] += A[i];
				turn++;
			}
			turn = 1;
			for (ll i = r - 1; i >= 1; i--) {
				ans[mod][turn] += A[i];
				ans[mod][turn + 1] += ans[mod][turn] / 10;
				ans[mod][turn] %= 10;
				turn++;
			}

			for (ll i = 1; i <= n; i++) {
				ans[mod][i + 1] += ans[mod][i] / 10;
				ans[mod][i] %= 10;
				if (ans[mod][i] != 0)last[mod] = i;
			}
		
	}
	if (r <= n && l > 0) {
		if (last[1] == last[0]) {
			ll flag = 1;
			for (ll i = last[1]; i >= 1; i--) {
				if (ans[1][i] < ans[0][i]) {
					flag = 2;
					break;
				}
				if (ans[0][i] < ans[1][i]) {
					flag = 1;
					break;
				}
			}
			if (flag == 1) {
				co(0, last[0]);
			}
			else {
				co(1, last[1]);
			}
		}
		else {
			if (last[1] < last[0])co(1, last[1]);
			else co(0, last[0]);
		}
	}
	else {
		if (l > 0)co(0, last[0]);
		else co(1, last[1]);
	}
	return 0;
}