//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 1010;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, m, vis[maxn][maxn], a[maxn][maxn], t, cnt;
string s[maxn];
pll vec;
bool ok;

void dfs(ll x, ll y){
	vis[x][y] = 1;
	for(ll i = x - 1; i <= x + 1; i++){
		for(ll j = y - 1; j <= y + 1; j++){
			if(!(1 <= i && i <= n && 1 <= j && j <= m)){
				ok = 0;
				continue;
			}
			if(s[i][j] == '1'){
				if(a[i][j] == t) continue;
				a[i][j] = t;
				vis[i][j] = 0;
				cnt++;
				vec = Mp(i, j);
			}
			else if(!vis[i][j]) dfs(i, j);
		}
	}
}
void dfs2(ll x, ll y){
	if(vis[x][y]) return;
	cnt--;
	vis[x][y] = 1;
	ll i, j, c = 0;
	i = x - 1;
	j = y;
	if(a[i][j] == a[x][y]){
		c++;
		dfs2(i, j);
	}
	i = x + 1;
	j = y;
	if(a[i][j] == a[x][y]){
		c++;
		dfs2(i, j);
	}
	i = x;
	j = y - 1;
	if(a[i][j] == a[x][y]){
		c++;
		dfs2(i, j);
	}
	i = x;
	j = y + 1;
	if(a[i][j] == a[x][y]){
		c++;
		dfs2(i, j);
	}
	if(c != 2) ok = 0;
}

int main(){
	fast_io;
	
	cin >> n >> m;
	for(ll i = 1; i <= n; i++){
		cin >> s[i];
		s[i] = ' ' + s[i];
	}
	ll ans = 0;
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= m; j++){
			if(s[i][j] == '1' && s[i - 1][j] == '1' && s[i - 1][j - 1] == '1' && s[i][j - 1] == '1') ans = max(ans, 4);
			if(s[i][j] == '1' || vis[i][j]) continue;
			vec = Mp(0, 0);
			cnt = 0;
			t = i * maxn + j;
			ok = 1;
			dfs(i, j);
			if(vec.F == 0) continue;
			ll cnt2 = cnt;
			dfs2(vec.F, vec.S);
			if(ok && cnt == 0) ans = max(ans, cnt2);
		}
	}
	cout << ans;
	
	return 0;
}