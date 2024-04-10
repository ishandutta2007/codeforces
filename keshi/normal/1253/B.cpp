//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a, cnt;

bool in[maxn], out[maxn];

vector<ll> v, ans;

int main(){
	fast_io;
	
	cin >> n;
	
	ans.pb(0);
	
	for(ll i = 1; i <= n; i++){
		cin >> a;
		if(a > 0){
			if(in[a]){
				cout << -1;
				return 0;
			}
			in[a] = 1;
			cnt++;
			v.pb(a);
		}
		else{
			a = -a;
			if(!in[a] || out[a]){
				cout << -1;
				return 0;
			}
			out[a] = 1;
			cnt--;
		}
		if(cnt == 0){
			ans.pb(i);
			for(ll j = 0; j < v.size(); j++){
				in[v[j]] = 0;
				out[v[j]] = 0;
			}
			v.clear();
		}
	}
	
	if(cnt != 0){
		cout << -1;
		return 0;
	}
	
	cout << ans.size() - 1 << endl;
	
	for(ll i = 1; i < ans.size(); i++){
		cout << ans[i] - ans[i - 1] << " ";
	}
	
	return 0;
}