#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define si short int
#define speed ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pill pair<ll,ll>
#define f first
#define s second
#define pilc pair<ll,char>
#define all(a) (a).begin(),(a).end()
#define rep(s,e,step) for(int i = (s); i < (e) ; i += step)
#define vrep(s,e,step) for(int j = (s); j < (e) ; j += step)
#define ex exit(0)
#define sz(a) (a).size()


using namespace std;

const ll N = 1e5;
const ll big = 1e18;
const ll block = 800;
const ll mod = 1e6;

ll a[N];

ll pref[N];

int main() {
    speed;
	ll n, l, r, q1, q2;
	cin >> n >> l >> r >> q1 >> q2;
	ll ans = INT_MAX;
	rep(1, n + 1, 1)
		cin >> a[i],pref[i] = pref[i - 1] + a[i];
	for(int i = 0 ; i <= n ; i++) {
		ll F = pref[i];
		ll D = pref[n] - pref[i];
		ll R = n - i;
		ans = min(ans, F * l + D * r + max(0ll , (R > i ? (R - i - 1) * q2 : (i - R - 1) * q1)));
	}
	cout << ans;
}

/*
	Code written by
	Codeforces : I_Love_Trott
	mail : dzhon.snoudin@mail.ru
*/