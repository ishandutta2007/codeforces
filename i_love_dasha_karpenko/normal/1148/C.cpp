#include <bits/stdc++.h>

using namespace std;
#define DIM 300007
#define DIM2 200007
#define DIM3 200007
#define INF 10E16
#define MAXN 2750137
#define LG 18
#define MODULO 998244353
#define fi first
#define sc second
#define pb push_back
#define pu push
#define sz size()
#define po(power) ( 1<<power)
#define schnell ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"

typedef  int ll;
typedef long double ld;
const ld eps = 0.00000001;
const ll MASK(1 << 10);
const ll MC = 5007;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef ll msk[MASK + 7];
typedef vector<ll> vec;
typedef pair<string, string> ps;
#define forn(i,n) for (ll i = 1;i<=n;i++)
#define fore(y,i,n) for (ll i = y;i<=n;i++)

ll n, A[DIM],pos[DIM];
queue<pll> Q;
ll half(ll x) {
	if (x <= n / 2)return 1;
	return 2;
}
void so(ll x) {
	if (half(x) == 1) {
		pos[A[n]] = x;
		pos[A[x]] = n;
		swap(A[x], A[n]);
		Q.push({ x,n });
	}
	else {
		pos[A[1]] = x;
		pos[A[x]] = 1;
		swap(A[x], A[1]);
		Q.push({ 1,x });
	}
}
void st(ll x) {
	ll p1 = x, p2 = pos[x];
	if (p1 == p2)return;
	if (p1 == 1 && p2 == n) {
		pos[A[1]] = n;
		pos[A[n]] = 1;
		swap(A[1], A[n]);
		Q.push({ 1,n });
		return;
	}
	if (half(p1) != half(p2)) {
		if (p1 == 1) {
			pos[A[1]] = p2;
			pos[A[p2]] = 1;
			swap(A[1], A[p2]);
			Q.push({ 1,p2 });
			return;
		}
		if (p2 == n) {
			pos[A[n]] = p1;
			pos[A[p1]] = n;
			swap(A[n], A[p1]);
			Q.push({ p1,n });
			return;
		}
		so(p1);
		so(p2);
		pos[A[1]] = n;
		pos[A[n]] = 1;
		swap(A[1], A[n]);
		Q.push({ 1,n });
		so(p1);
		so(p2);
		
		
	}
	else {
		if (p1 == 1) {
			so(p2);
			so(p1);
			so(p2);
			return;
		}
		if (p2 == n) {
			so(p2);
			so(p1);
			so(p2);
			return;
		}
		so(p2);
		so(p1);
		so(p2);
		
	}
	
}
int main()
{
	schnell;
	cin >> n;
	forn(i, n) {
		cin >> A[i];
		pos[A[i]] = i;
	}
	
	forn(i, n-1) {
		st(i);
		//cout << A[i] << ' ';
	}
	//cout << endl;
	cout << Q.size() << endl;
	while (!Q.empty()) {
		cout << Q.front().first << ' ' << Q.front().second << endl;
		Q.pop();
	}
}
// (a+k)%(b+k)
// a-b*x;