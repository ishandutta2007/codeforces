#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9+7;
ll N, M, ans=1;

ll mypow(ll a, ll x) {
	ll ret = 1;
	while (x) {
		if (x&1) ret = ret*a%mod;
		a=a*a%mod; x/=2;
	}
	return ret;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> N >> M;
	cout << mypow((mypow(2, M)-1), N);

}