#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define X first
#define Y second

ll t, n, a[MAXN], b, x, ans, o, y, j;

string s;

int main(){
	fast_io;
	
	cin >> t;
	
	while(t--){
		ans = 0;
		cin >> s;
		n = s.size();
		a[n] = n + 1;
		for(ll i = n - 1; i > -1; i--){
			if(s[i + 1] == '1'){
				a[i] = i + 1;
			}
			else{
				a[i] = a[i + 1];
			}
		}
		
		for(ll i = 0; i < n; i++){
			if(s[i] == '1'){
				ans++;
				if(i + 1 < n && s[i + 1] == '0'){
					ans++;
				}
			}
			else{
				b = a[i];
				x = b - i;
				o = 0;
				y = x;
				j = a[i];
				while(j < n && o * 2 + (s[j] - '0') <= y + 1){
					o = o * 2 + (s[j] - '0');
					y++;
					j++;
					if(o == y){
						ans++;
						break;
					}
				}
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}