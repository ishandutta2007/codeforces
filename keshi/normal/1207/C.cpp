// In the name of GOD
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define X first
#define Y second

ll t, n, a, b, l, c, d, ans;
vector<ll> v;
bool u;
string s;

bool cal(ll x){
	if(2 * a < (x - 1) * b){
		return 1;
	}
	return 0;
}

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> n >> a >> b >> s;
		v.clear();
		u = 0;
		l = 0;
		d = n;
		c = n + 1;
		for(ll i = 1; i < n; i++){
			if(s[i] == '1'){
				c++;
			}
			if(s[i] != s[i - 1]){
				if(s[i - 1] == '0'){
					c++;
					if(u){
						v.pb(i - l);
					}
					u = 1;
				}
				l = i;
			}
		}
		//cout << c << endl;
		for(ll i = 0; i < v.size(); i++){
			//cout << v[i] << " ";
			if(cal(v[i])){
				//cout << "YES ";
				d += 2;
			}
			else{
				c += v[i] - 1;
			}
		}
		if(c > n + 1){
			d += 2;
		}
		cout << c * b + d * a << endl;
	}
	
	return 0;
}