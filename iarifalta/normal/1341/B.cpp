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

const ll N = 1;
const ll big = 1e18;
const ll block = 800;
const ll mod = 1e6;

ll t;

int main() {
    speed;
	cin >> t;
	while(t--) {
		ll n, k;
		cin >> n >> k;
		ll a[n + 1];
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		ll p = 0;
		for(int j = 2; j < k; j++) {
			if(a[j] > a[j - 1] && a[j + 1] < a[j])
				p++;	
		}
		pill ans = {p, 1};
		for(int i = 2; i <= n - k + 1; i++) {
			if(a[i] > a[i - 1] && a[i] > a[i + 1])
				p--;
			if(a[i + k - 2] > a[i + k - 1] && a[i + k - 2] > a[i + k - 3])
				p++;
			if(ans.f < p)
				ans = {p, i};
//			ans = max(ans, {p, i});
		}
		cout << ans.f + 1 << " " << ans.s << '\n';
	}
}

/*
1
7 5
1 2 3 4 5 6 1
*/