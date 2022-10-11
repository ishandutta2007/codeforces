//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, x, a[maxn], b[maxn];

vector<ll> q, ans;

int main(){
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 0; i < n; i++){
		cin >> x;
		a[x % m]++;
	}
	for(ll i = 0; i < n; i++){
		cin >> x;
		b[(m - 1 - x % m) % m]++;
	}
	
	for(ll i = 0; i < m; i++){
		while(a[i]){
			q.pb(i);
			a[i]--;
		}
		while(!q.empty() && b[i]){
			ans.pb(q.back() + m - 1 - i);
			q.pop_back();
			b[i]--;
		}
	}
	for(ll i = 0; i < m; i++){
		while(a[i]){
			q.pb(i);
			a[i]--;
		}
		while(!q.empty() && b[i]){
			ans.pb((q.back() + m - 1 - i) % m);
			q.pop_back();
			b[i]--;
		}
	}
	
	sort(ans.begin(), ans.end(), greater<ll>());
	
	for(ll i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
	
	return 0;
}