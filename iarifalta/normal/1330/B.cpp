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
#define ex exit(0)

using namespace std;

const ll N = 2e5 + 10;
const ll big = 1e18;
const ll block = 800;
const ll mod = 1e6;

ll t;

bool b[N];
bool c[N];

int main() {
    speed;
    cin >> t;
    while(t--){
    	ll n;
    	cin >> n;
    	bool pref[n + 1],suf[n + 1];
    	ll a[n];
    	for(int i = 0 ; i < n; i++)
    		cin >> a[i], pref[i] = suf[i] = 0;
    	ll l = 0;
    	ll mx = 0, cnt = 0;
    	for(l = 0; l < n; l++){
    		if(b[a[l]])
    			break;
			b[a[l]] = 1;
			mx = max(mx, a[l]);
			cnt++;
			if(cnt == mx)
				pref[l] = 1;
		}
		mx = 0, cnt = 0;
		for(int j = n - 1 ; j >= 0 ; j--){
			if(c[a[j]])
				break;
			c[a[j]] = 1;
			mx = max(mx, a[j]);
			cnt++;
			if(cnt == mx)
				suf[j] = 1;
		}
		vector<pill> z;
		for(int i = 0 ; i < n  ; i++){
			if(pref[i] && suf[i + 1])
				z.pb({i + 1,n - i - 1});
		}
		cout << z.size() << '\n';
		for(auto u : z)
			cout << u.f << " " << u.s << '\n';
		for(int i = 0 ; i <= n ; i++)
			b[i] = c[i] = 0;
		
	}
}