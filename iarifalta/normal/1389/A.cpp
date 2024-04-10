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

const ll N = 2e5;
const ll big = 1e18;
const ll block = 800;
const ll mod = 1e6;



void solve() {
	ll l, r;
	cin >> l >> r;
	if(2 * l <= r)
		cout << l << ' ' << l * 2 << '\n';
	else
		cout << -1 << " " << -1 << '\n';
}

int main() {
    speed;
    ll t;
    cin >> t;
    while(t--) {
    	solve();
	}

}

/*
13 21
*/