//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e4 + 100;
const ll maxm = 1010;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, g, r, v, t, a[maxn];

pll dis[maxn][maxm];

bool vis[maxn][maxm];

deque<ll> q;

int main(){
	//fast_io;
	
	cin >> n >> m;
	
	for(ll i = 0; i < m; i++){
		cin >> a[i];
	}
	
	sort(a, a + m);
	
	cin >> g >> r;
	
	for(ll i = g; i--;){
		vis[m - 1][i] = 1;
		dis[m - 1][i].F = 0;
		dis[m - 1][i].S = g - i;
		q.push_back((m - 1) * maxm + i);
	}
	
	while(!q.empty()){
		v = q.front() / maxm;
		t = q.front() % maxm;
		q.pop_front();
		if(t == g){
			if(!vis[v][0]){
				vis[v][0] = 1;
				dis[v][0].F = dis[v][t].F + 1;
				dis[v][0].S = dis[v][t].S;
				q.push_back(v * maxm);
			}
		}
		if(v + 1 < m && t + a[v + 1] - a[v] <= g && !vis[v + 1][t + a[v + 1] - a[v]]){
			vis[v + 1][t + a[v + 1] - a[v]] = 1;
			dis[v + 1][t + a[v + 1] - a[v]] = dis[v][t];
			q.push_front((v + 1) * maxm + t + a[v + 1] - a[v]);
		}
		if(v - 1 >= 0 && t + a[v] - a[v - 1] <= g && !vis[v - 1][t + a[v] - a[v - 1]]){
			vis[v - 1][t + a[v] - a[v - 1]] = 1;
			dis[v - 1][t + a[v] - a[v - 1]] = dis[v][t];
			q.push_front((v - 1) * maxm + t + a[v] - a[v - 1]);
		}
	}
	
	if(!vis[0][g]) cout << -1;
	else cout << dis[0][g].F * (r + g) + dis[0][g].S;
	
	return 0;
}