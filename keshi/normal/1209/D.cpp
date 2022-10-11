//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k, x[maxn], y[maxn], ans, p, ptr;

vector<ll> a[maxn];
queue<ll> q;

bool used[maxn], in[maxn], ate[maxn];

int main(){
	fast_io;
	
	cin >> n >> k;
	
	for(ll i = 0; i < k; i++){
		cin >> x[i] >> y[i];
		a[x[i]].pb(i);
		a[y[i]].pb(i);
	}
	ptr = 1;
	while(ptr <= n){
		if(q.empty()){
			while(in[ptr]){
				ptr++;
			}
			if(ptr > n){
				break;
			}
			q.push(ptr);
			in[ptr] = 1;
		}
		for(ll i = 0; i < a[q.front()].size(); i++){
			p = a[q.front()][i];
			if(ate[p]) continue;
			if(used[x[p]] && used[y[p]]){
				ans++;
			}
			used[x[p]] = 1;
			used[y[p]] = 1;
			ate[p] = 1;
			if(!in[x[p]]){
				q.push(x[p]);
				in[x[p]] = 1;
			}
			if(!in[y[p]]){
				q.push(y[p]);
				in[y[p]] = 1;
			}
		}
		q.pop();
	}
	
	cout << ans;
	
	return 0;
}