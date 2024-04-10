//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, x, y, a, b, ans, ans2, pa[maxn], pb[maxn];
string s;

int main(){
    fast_io;

	cin >> s >> x >> y;
	n = Sz(s);
	for(ll i = 0; i < n; i++){
		if(s[i] == '1'){
			ans += a * x;
			b++;
		}
		else{
			ans += b * y;
			a++;
		}
	}
	for(ll i = n; i--;){
		pa[i] = pa[i + 1] + (s[i] != '1');
		pb[i] = pb[i + 1] + (s[i] == '1');
	}
	ans2 = ans;
	a = b = 0;
	for(ll i = 0; i < n; i++){
		if(s[i] == '?'){
			ans += a * x - b * y + pa[i + 1] * y - pb[i + 1] * x;
			ans2 = min(ans2, ans);
		}
		if(s[i] == '0') a++;
		else b++;
	}
	for(ll i = n; i--;){
		pa[i] = pa[i + 1] + (s[i] == '0');
		pb[i] = pb[i + 1] + (s[i] != '0');
	}
	a = b = 0;
	for(ll i = 0; i < n; i++){
		if(s[i] == '?'){
			ans -= a * x - b * y + pa[i + 1] * y - pb[i + 1] * x;
			ans2 = min(ans2, ans);
		}
		if(s[i] == '1') b++;
		else a++;
	}

	cout << ans2;

    return 0;
}