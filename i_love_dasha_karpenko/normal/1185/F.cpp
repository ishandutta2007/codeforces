#include <bits/stdc++.h>

using namespace std;
#define DIM  200007
#define DIM2 107
#define INF 10E16
#define MAXN 2750137
#define LG 18
#define MODULO 1000000007

typedef long long ll;
const ll MASK(1 << 10);
typedef long double ld;
typedef pair<ll, ll> pll;
typedef ll arr[DIM];
typedef ll msk[MASK+7];
typedef vector<ll> vec;
typedef vector<ll> graph[DIM];
typedef pll parr[DIM];
typedef ll table[DIM][DIM2];
typedef ll arr2[DIM2];
typedef pair<string, string> ps;
#define forn(i,n) for (ll i = 1;i<=n;i++)
#define fore(y,i,n) for (ll i = y;i<=n;i++)
#define fi first
#define sc second
#define pb push_back
#define pu push
#define sz size()
#define po(power) ( 1<<power)
#define schnell ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
ll n, m;
msk C,P,num,V,PP,nu;
int main()
{
	schnell;
	cin >> n >> m;
	forn(i, MASK)C[i] = 0;
	forn(i,n){
		ll mask = 0;
		ll k; cin >> k;
		forn(j, k) {
			ll x; cin >> x;
			mask += po(x);
		}
		C[mask]++;
	}

	memset(num, -1, sizeof(num));
	memset(nu, -1, sizeof(nu));
	forn(i, m) {
		ll p, k,mask = 0; cin >> p >> k;
		forn(j, k) {
			ll x; cin >> x;
			mask += po(x);
		}
		if (num[mask] == -1) {
			num[mask] = i;
			P[mask] = p;
		}
		else  {
			if (p < P[mask]) {
				PP[mask] = P[mask];
				P[mask] = p;
				nu[mask] = num[mask];
				num[mask] = i;
			}
			else {
				if (nu[mask] == -1) {
					PP[mask] = p;
					nu[mask] = i;
				}
				else if (PP[mask] > p) {
					PP[mask] = p;
					nu[mask] = i;
				}
			}
		}
	}
	ll maxres = 0, price = INF;
	pll ans;
	forn(i, MASK) {
		fore(i,j, MASK) {
			if (num[i] == -1 || num[j] == -1)continue;
			if (i == j) {
				if (nu[i] == -1)continue;
				ll res = 0, p = P[i] + PP[i], mask = i;
				memset(V, 0, sizeof(V));
				for (int s = mask; s != 0; s = (s - 1) & mask) {
					if (V[s])continue;
					res += C[s];
					V[s] = 1;
				}
				if (maxres < res) {
					maxres = res;
					price = p;
					ans = { num[i],nu[j] };
				}
				else if (maxres == res && p < price) {
					price = p;
					ans = { num[i],nu[j] };
				}
				continue;
			}
			ll res = 0, p = P[i]+P[j],mask = i|j;
			memset(V, 0, sizeof(V));
			for (int s = mask; s != 0; s = (s - 1) & mask) {
				if (V[s])continue;
				res += C[s];
				V[s] = 1;
			}
			if (maxres < res) {
				maxres = res;
				price = p;
				ans = { num[i],num[j] };
			}
			else if (maxres == res && p < price) {
				price = p;
				ans = { num[i],num[j] };
			}
			//cout << res << endl;
		}
	}
	cout << ans.first<<' '<<ans.sc<< endl;
	return 0;
}