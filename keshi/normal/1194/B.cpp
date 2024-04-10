#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e4 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

ll q, n, m, ans, a[MAXN], b[MAXN];
string s[MAXN];

int main(){
	fast_io;
	cin >> q;
	while(q--){
		cin >> n >> m;
		fill(a, a + n, 0);
		fill(b, b + m, 0);
		ans = INF;
		for(int i = 0; i < n; i++){
			cin >> s[i];
			for(int j = 0; j < m; j++){
				if(s[i][j] == '.'){
					a[i]++;
					b[j]++;
				}
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(s[i][j] == '.'){
					ans = min(ans, a[i] + b[j] - 1);
				}
				else{
					ans = min(ans, a[i] + b[j]);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}