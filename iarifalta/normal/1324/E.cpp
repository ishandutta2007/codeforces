#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define si short int
#define speed ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pill pair<ll,ll>
#define f first
#define s second

using namespace std;

const ll N = 2e3 + 10;
const ll big = 1e18;
const ll block = 100;
const ll mod = 1e6;

ll n;
ll h;
ll l;
ll r;

ll a[N];
ll dp[N][N];
bool was[N][N];

ll rec(ll i,ll x){
	if(i == n)
		return (l <= x && x <= r);
	if(was[i][x])
		return dp[i][x];
	ll ans = (l <= x && x <= r && i != 0);
	ans += max(rec(i + 1 , (x + a[i]) % h), rec(i + 1, (x + a[i] - 1) % h));
	was[i][x] = 1;
	dp[i][x] = ans;
	return ans;
}

int main() {
	speed;
	cin >> n >> h >> l >> r;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i];
	}
	
	cout << rec(0 , 0);
}
/*
	3
	3 2 1
	1 2 3

	2 0 -2
	-2 -2 0 2
	Code written by
	Codeforces : I_Love_Trott
	mail : dzhon.snoudin@mail.ru
*/