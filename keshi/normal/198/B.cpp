//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k, dis[2][maxn], c, x;

string s[2];

queue<pll> q;

int main(){
	fast_io;
	
	cin >> n >> k;
	
	cin >> s[0] >> s[1];
	
	fill(dis[0], dis[0] + maxn, inf);
	fill(dis[1], dis[1] + maxn, inf);
	
	q.push({0, 0});
	dis[0][0] = 0;
	
	while(!q.empty()){
		c = q.front().F;
		x = q.front().S;
		q.pop();
		if(dis[c][x] > x || s[c][x] == 'X') continue;
		if(x >= n){
			cout << "YES";
			return 0;
		}
		if(dis[c][x + 1] > dis[c][x] + 1){
			q.push({c, x + 1});
			dis[c][x + 1] = dis[c][x] + 1;
		}
		if(x > 0 && dis[c][x - 1] > dis[c][x] + 1){
			q.push({c, x - 1});
			dis[c][x - 1] = dis[c][x] + 1;
		}
		if(dis[1 - c][x + k] > dis[c][x] + 1){
			q.push({1 - c, x + k});
			dis[1 - c][x + k] = dis[c][x] + 1;
		}
	}
	
	cout << "NO";
	
	return 0;
}