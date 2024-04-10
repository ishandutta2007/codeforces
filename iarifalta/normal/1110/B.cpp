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

const ll N = 1e5 + 10;
const ll big = 1e18;
const ll block = 800;
const ll mod = 2;

ll n, m, k;

ll a[N];

set<pill> x;

int main() {
    speed;
	cin >> n >> m >> k;
	for(int i = 1 ; i <= n ; i++) {
		cin >> a[i];
		if(i > 1)
			x.insert({a[i] - a[i - 1], i});
	}
	ll otr = n;
	ll ans = 0;
	while(otr > k) {
		ans += (*x.begin()).f;
		auto it = x.begin();
		x.erase(it);
		otr--;
	}
	cout << ans + k << '\n';
}

/*
	Code written by
	Codeforces : I_Love_Trott
	mail : dzhon.snoudin@mail.ru
*/