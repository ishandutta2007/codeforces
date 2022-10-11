//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 100;
const ll maxm = 61;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a[maxn], cnt[maxm], dis[maxn], ans, m, v, c;

vector<ll> vec;

queue<ll> q;

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		for(ll j = 0; j < maxm; j++){
			if((a[i] >> j) & 1) cnt[j]++;
			if(cnt[j] > 2){
				cout << 3;
				return 0;
			}
		}
		if(a[i]){
			vec.pb(a[i]);
		}
	}
	
	ans = inf;
	
	m = vec.size();
	
	for(ll i = 0; i < m; i++){
		fill(dis, dis + m, inf);
		dis[i] = 0;
		q.push(i);
		while(!q.empty()){
			v = q.front();
			q.pop();
			c = 0;
			for(ll j = 0; j < m; j++){
				if((vec[v] & vec[j]) && (v != j)){
					if(dis[j] < dis[v]) c++;
					else if(dis[j] == dis[v]) ans = min(ans, dis[v] * 2 + 1);
					else{
						dis[j] = dis[v] + 1;
						q.push(j);
					}
				}
			}
			if(c > 1) ans = min(ans, dis[v] * 2);
		}
	}
	
	if(ans == inf) ans = -1;
	
	cout << ans;
	
	return 0;
}