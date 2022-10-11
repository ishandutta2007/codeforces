#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3000 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll int
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define X first
#define Y second

ll n, m, a, b, ans[MAXN][MAXN];
long long g, x, y, z, o;
deque <ll> dq, di;

int main(){
	fast_io;
	
	cin >> n >> m >> a >> b;
	cin >> g >> x >> y >> z;
	
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < m; j++){
			ans[i][j] = g;
			//cout << ans[i][j] << " ";
			g = (g * x + y) % z;
		}
		//cout << endl;
	}
	
	for(ll i = 0; i < n; i++){
		dq.clear();
		di.clear();
		for(ll j = m; j > -1; j--){
			while(!dq.empty() && dq.back() >= ans[i][j]){
				dq.pop_back();
				di.pop_back();
			}
			
			if(!dq.empty() && di.front() - j >= b){
				di.pop_front();
				dq.pop_front();
			}
			
			dq.push_back(ans[i][j]);
			di.push_back(j);
			
			ans[i][j] = dq.front();
		}
	}
	
	for(ll j = 0; j < m; j++){
		dq.clear();
		di.clear();
		for(ll i = n; i > -1; i--){
			while(!dq.empty() && dq.back() >= ans[i][j]){
				dq.pop_back();
				di.pop_back();
			}
			
			if(!dq.empty() && di.front() - i >= a){
				di.pop_front();
				dq.pop_front();
			}
			
			dq.push_back(ans[i][j]);
			di.push_back(i);
			
			ans[i][j] = dq.front();
		}
	}
	
	//cout << endl;
	
	for(ll i = 0; i < n - a + 1; i++){
		for(ll j = 0; j < m - b + 1; j++){
			//cout << ans[i][j] << " ";
			o += ans[i][j];
		}
		//cout << endl;
	}
	
	cout << o;
	
	
	return 0;
}