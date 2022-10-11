#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e6 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define X first
#define Y second

string s;

ll a[10][10], x, y, n, ans, cnt[10][10];
bool visited[10], ride;

void bfs(ll v){
	fill(visited, visited + 10, 0);
	vector<ll> b;
	ll z, u, ptr = 0;
	//a[v][v] = 0;
	b.pb(v);
	//visited[v] = 1;
	while(ptr < b.size()){
		u = b[ptr];
		z = (u + x) % 10;
		if(!visited[z]){
			b.pb(z);
			visited[z] = 1;
			a[v][z] = a[v][u] + 1;
			if(u == v){
				a[v][z] = 1;
			}
		}
		z = (u + y) % 10;
		if(!visited[z]){
			b.pb(z);
			visited[z] = 1;
			a[v][z] = a[v][u] + 1;
			if(u == v){
				a[v][z] = 1;
			}
		}
		ptr++;
	}
}

int main(){
	fast_io;
	
	cin >> s;
	n = s.size();
	for(ll i = 0; i < n - 1; i++){
		cnt[s[i] - '0'][s[i + 1] - '0']++;
	}
	
	for(x = 0; x < 10; x++){
		for(y = 0; y < 10; y++){
			for(ll i = 0; i < 10; i++){
				for(ll j = 0; j < 10; j++){
					a[i][j] = -1;
				}
				bfs(i);
			}
			ans = - n + 1;
			ride = 0;
			for(ll i = 0; i < 10; i++){
				for(ll j = 0; j < 10; j++){
					if(cnt[i][j]){
						if(a[i][j] == -1){
							ride = 1;
						}
						else{
							ans += a[i][j] * cnt[i][j];
						}
					}
				}
			}
			if(ride)
			{
			    ans = -1;
			}
			cout << ans << " ";
		}
		cout << endl;
	}
	
	return 0;
}