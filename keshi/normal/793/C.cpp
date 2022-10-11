//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const ld eps = 1e-7;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define pld pair<ld, ld>
#define F first
#define S second

ll n, c;

ld l, r, u, d, t, x, y, vx, vy, t1, t2;

bool f;

vector<pair<ld, bool> > a;

int main(){
	fast_io;
	cout << setprecision(10);
	
	cin >> n;
	cin >> l >> u >> r >> d;
	
	if(l == r || u == d){
		cout << -1;
		return 0;
	}
	
	if(l > r) swap(l, r);
	if(u > d) swap(u, d);
	
	for(ll i = 0; i < n; i++){
		cin >> x >> y >> vx >> vy;
		if(l < x && x < r && u < y && y < d){
			if(vx != 0 || vy != 0){
				t2 = 1000000;
				if(vx && u < y + vy * (l + eps - x) / vx && y + vy * (l + eps - x) / vx < d && (l + eps - x) / vx >= 0){
					t2 = min(t2, (l + eps - x) / vx);
				}
				if(vx && u < y + vy * (r - eps - x) / vx && y + vy * (r - eps - x) / vx < d && (r - eps - x) / vx >= 0){
					t2 = min(t2, (r - eps - x) / vx);
				}
				if(vy && l < x + vx * (u + eps - y) / vy && x + vx * (u + eps - y) / vy < r && (u + eps - y) / vy >= 0){
					t2 = min(t2, (u + eps - y) / vy);
				}
				if(vy && l < x + vx * (d - eps - y) / vy && x + vx * (d - eps - y) / vy < r && (d - eps - y) / vy >= 0){
					t2 = min(t2, (d - eps - y) / vy);
				}
				a.pb({0, 0});
				a.pb({t2, 1});
				c++;
			}
		}
		else{
			t1 = -1;
			t2 = 1000000;
			f = 0;
			if(vx && u < y + vy * (l + eps - x) / vx && y + vy * (l + eps - x) / vx < d && (l + eps - x) / vx >= 0){
				f = 1;
				t1 = max(t1, (l + eps - x) / vx);
				t2 = min(t2, (l + eps - x) / vx);
			}
			if(vx && u < y + vy * (r - eps - x) / vx && y + vy * (r - eps - x) / vx < d && (r - eps - x) / vx >= 0){
				f = 1;
				t1 = max(t1, (r - eps - x) / vx);
				t2 = min(t2, (r - eps - x) / vx);
			}
			if(vy && l < x + vx * (u + eps - y) / vy && x + vx * (u + eps - y) / vy < r && (u + eps - y) / vy >= 0){
				f = 1;
				t1 = max(t1, (u + eps - y) / vy);
				t2 = min(t2, (u + eps - y) / vy);
			}
			if(vy && l < x + vx * (d - eps - y) / vy && x + vx * (d - eps - y) / vy < r && (d - eps - y) / vy >= 0){
				f = 1;
				t1 = max(t1, (d - eps - y) / vy);
				t2 = min(t2, (d - eps - y) / vy);
			}
			if(!f){
				cout << -1;
				return 0;
			}
			a.pb({t2, 0});
			a.pb({t1, 1});
			c++;
		}
	}
	
	sort(a.begin(), a.end());
	
	if(c == 0){
		cout << 0;
		return 0;
	}
	
	for(ll i = 0; i < a.size(); i++){
		if(a[i].S){
			c++;
		}
		else{
			c--;
			if(c == 0){
				cout << a[i].F;
				return 0;
			}
		}
	}
	
	cout << -1;
	
	return 0;
}