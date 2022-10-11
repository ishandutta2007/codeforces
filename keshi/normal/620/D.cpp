//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e3 + 10;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, a[maxn], b[maxn], sa, sb, ans0, ans1, ans2, ans, x, y;

pll p1, p2[2];

set<pair<ll, pll> > s;

set<pair<ll, pll> >::iterator z;

int main(){
	ll g, u;
	fast_io;

	cin >> n;

	for(ll i = 0; i < n; i++){
        cin >> a[i];
        sa += a[i];
	}

	cin >> m;

	for(ll i = 0; i < m; i++){
        cin >> b[i];
        sb += b[i];
	}
	ans0 = abs(sa - sb);
	ans1 = inf;
	for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            if(abs(sa - sb + 2 * (b[j] - a[i])) < ans1){
                ans1 = abs(sa - sb + 2 * (b[j] - a[i]));
                p1 = {i, j};
            }
        }
	}

	for(ll i = 0; i < m; i++){
        for(ll j = i + 1; j < m; j++){
            s.insert({2 * (b[i] + b[j]), {i, j}});
        }
	}

	ans2 = inf;


	if(m != 1){

	for(ll i = 0; i < n; i++){
        for(ll j = i + 1; j < n; j++){
            x = 2 * (a[i] + a[j]);
            y = sb - sa + x;
            z = s.lower_bound({y, {-1, -1}});
            if(z != s.end()){
                if(ans2 > abs(sa - sb - x + z -> F)){
                    ans2 = abs(sa - sb - x + z -> F);
                    p2[0] = {i, j};
                    p2[1] = z -> S;
                }
            }
            z = s.upper_bound({y, {-1, -1}});
            z--;
            if(z != s.end()){
                if(ans2 > abs(sa - sb - x + z -> F)){
                    ans2 = abs(sa - sb - x + z -> F);
                    p2[0] = {i, j};
                    p2[1] = z -> S;
                }
            }
        }
	}

	}

	ans = min(ans0, min(ans1, ans2));

	cout << ans << endl;

	if(ans0 == ans){
        cout << 0;
        return 0;
	}

	if(ans1 == ans){
        cout << 1 << endl;
        cout << p1.F + 1 << " " << p1.S + 1;
        return 0;
	}

	cout << 2 << endl;

	cout << p2[0].F + 1 << " " << p2[1].F + 1 << endl;
	cout << p2[0].S + 1 << " " << p2[1].S + 1;

	return 0;
}