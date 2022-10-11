//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 60;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, a, b, dis[maxn][maxn][2], ans[maxn][maxn][2], x, y, c, C[maxn][maxn];

queue<pair<pll, bool> > q;

int main(){
	fast_io;
	
	C[0][0] = 1;
	
	for(ll i = 0; i < maxn; i++){
		for(ll j = 0; j < maxn; j++){
			dis[i][j][0] = inf;
			dis[i][j][1] = inf;
			if(i){
				C[i][j] = C[i - 1][j];
				if(j){
					C[i][j] = (C[i][j] + C[i - 1][j - 1]) % mod;
				}
			}
		}
	}
	
	cin >> n >> m;
	
	
	for(ll i = 0; i < n; i++){
		cin >> x;
		if(x == 50) a++;
		else b++;
	}
	
	q.push({{a, b}, 0});
	dis[a][b][0] = 0;
	ans[a][b][0] = 1;
	
	while(!q.empty()){
		x = q.front().F.F;
		y = q.front().F.S;
		c = q.front().S;
		q.pop();
		if(c){
			for(ll i = 0; i <= a - x; i++){
				for(ll j = 0; j <= b - y; j++){
					if(i + j > 0 && i * 50 + j * 100 <= m){
						if(dis[x + i][y + j][1 - c] > dis[x][y][c] + 1){
							dis[x + i][y + j][1 - c] = dis[x][y][c] + 1;
							q.push({{x + i, y + j}, 1 - c});
						}
						if(dis[x + i][y + j][1 - c] == dis[x][y][c] + 1){
							ans[x + i][y + j][1 - c] += (ans[x][y][c] * C[a - x][i] * C[b - y][j]) % mod;
							ans[x + i][y + j][1 - c] %= mod;
						}
					}
				}
			}
		}
		else{
			for(ll i = 0; i <= x; i++){
				for(ll j = 0; j <= y; j++){
					if(i + j > 0 && i * 50 + j * 100 <= m){
						if(dis[x - i][y - j][1 - c] > dis[x][y][c] + 1){
							dis[x - i][y - j][1 - c] = dis[x][y][c] + 1;
							q.push({{x - i, y - j}, 1 - c});
						}
						if(dis[x - i][y - j][1 - c] == dis[x][y][c] + 1){
							ans[x - i][y - j][1 - c] += (ans[x][y][c] * C[x][i] * C[y][j]) % mod;
							ans[x - i][y - j][1 - c] %= mod;
						}
					}
				}
			}
		}
	}
	
	if(ans[0][0][1] == 0){
		dis[0][0][1] = -1;
	}
	
	cout << dis[0][0][1] << endl << ans[0][0][1];
	
	return 0;
}