#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200;

#define ll long long
#define file_io freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pll pair<ll, ll>
#define x first
#define y second
#define pb push_back

ll n;
string s[MAXN], c[MAXN], ans[MAXN];
vector<pll> o;

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> s[i];
		for(ll j = 0; j < n; j++){
			c[i] += '.';
			if(s[i][j] == 'o'){
				o.pb(make_pair(i, j));
			}
		}
	}
	
	for(ll i = 0; i < 2 * n - 1; i++){
		for(ll j = 0; j < 2 * n - 1; j++){
			ans[i] += 'x';
		}
	}
	
	for(ll dx = -(n - 1); dx <= n - 1; dx++){
		for(ll dy = -(n - 1); dy <= n - 1; dy++){
			for(ll k = 0; k < o.size(); k++){
				if(o[k].x + dx >= 0 && o[k].x + dx < n && o[k].y + dy >= 0 && o[k].y + dy < n){
					if(s[o[k].x + dx][o[k].y + dy] == '.'){
						ans[dx + n - 1][dy + n - 1] = '.';
						break;
					}
				}
			}
		}
	}
	
	ans[n - 1][n - 1] = 'o';
	
	for(ll k = 0; k < o.size(); k++){
		for(ll i = 0; i < n; i++){
			for(ll j = 0; j < n; j++){
				if(ans[i - o[k].x + n - 1][j - o[k].y  + n - 1] == 'x'){
					c[i][j] = 'x';
				}
			}
		}
	}
	
	for(ll k = 0; k < o.size(); k++){
		c[o[k].x][o[k].y] = 'o';
	}
	
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < n; j++){
			if(c[i][j] != s[i][j]){
				cout << "NO";
				return 0;
			}
		}
	}
	
	cout << "YES" << endl;
	for(ll i = 0; i < 2 * n - 1; i++){
		for(ll j = 0; j < 2 * n - 1; j++){
			cout << ans[i][j];
		}
		cout << endl;
	}
	
	return 0;
}