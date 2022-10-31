#include <bits/stdc++.h>

using namespace std;
#define DIM 200007
#define DIM2 107
#define INF 10E10
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

typedef long long ll;
typedef long double ld;

const ld eps = 0.00000001;
const ll MASK(1 << 10);

typedef pair<ll, ll> pll;
typedef ll arr[DIM];
typedef ll msk[MASK + 7];
typedef vector<ll> vec;
typedef vector<ll> graph[DIM];
typedef pll parr[DIM];
typedef ll table[DIM][DIM2];
typedef ll arr2[DIM2];
typedef pair<string, string> ps;
#define forn(i,n) for (ll i = 1;i<=n;i++)
#define fore(y,i,n) for (ll i = y;i<=n;i++)

ll n, x;
int main()
{
	schnell;
	cin >> n >> x;
	ll sum = 0, sumx = 0, mxsum = 0, mxsumx = 0,flag = 1,res = 0;
	forn(i, n) {
		ll a; cin >> a;
		
		sumx = max(sum + a * x, sumx + a * x);
		sum += a;
		if (flag == 0)mxsumx += a;
		else {
			if (a > a * x) {
				mxsumx += a;
				flag = 0;
			}
			else {
				mxsumx += a * x;
			}
		}
		if (sumx >= mxsumx) {
			mxsumx = sumx;
			flag = 1;
		}
		if (sum < 0)sum = 0;
		if (mxsumx < 0) {
			mxsumx = 0; flag = 1;
		}
		if (sumx < 0)sumx = 0;
		res = max(res,max(sum, mxsumx));
	}
	cout << res << endl;
	
	
}
// 1 2 3 2
// 1 3 7