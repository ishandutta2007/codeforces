//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef double ld;
typedef complex<ld> cd;
typedef pair<ll, ll> pll;

const ll maxn = 3e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;
const ld PI = acos(-1);

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

inline ll reverse(ll x, ll lg){
	ll y = 0;
	for(ll i = 0; i < lg; i++){
		if((x >> i) & 1) y += (1ll << (lg - i - 1));
	}
	return y;
}

void fft(cd* a, bool inv = 0){
	ll lg = 21;
	ll n = (1ll << lg);
	for(ll i = 0; i < n; i++){
		ll j = reverse(i, lg);
		if(i < j) swap(a[i], a[j]);
	}
	for(ll len = 2; len <= n; len *= 2){
		ld ang = 2 * PI / len * (inv ? -1 : 1);
		cd wlen(cos(ang), sin(ang));
		for(ll i = 0; i < n; i += len){
			cd w(1);
			for(ll j = 0; j < len / 2; j++){
				cd v = a[i + j], u = w * a[i + j + len / 2];
				a[i + j] = v + u;
				a[i + j + len / 2] = v - u;
				w *= wlen;
			}
		}
	}
	if(inv){
		for(ll i = 0; i < n; i++){
			a[i] /= n;
		}
	}
	return;
}

ll n, m;
bool vis[maxn];
cd a[maxn];

int main(){
    fast_io;
    
    cin >> n >> m;
    for(ll i = 0; i < n; i++){
    	ll x;
    	cin >> x;
    	a[x] = cd(1);
    	vis[x] = 1;
	}
	fft(a);
	for(ll i = 0; i < (1ll << 21); i++){
		a[i] = a[i] * a[i];
	}
	fft(a, 1);
	vector<ll> ans;
	for(ll i = 0; i <= m; i++){
		if(a[i].real() > 0.5 && !vis[i]){
			cout << "NO";
			return 0;
		}
		if(a[i].real() < 0.5 && vis[i]){
			ans.pb(i);
		}
	}
	cout << "YES\n" << Sz(ans) << "\n";
	for(ll i : ans){
		cout << i << " ";
	}
 
    return 0;
}