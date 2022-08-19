#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

int gcd(int x, int y){
	return y ? gcd(y, x%y) : x;
}

vector<pi> gph[400005];
vector<int> rev[400005], dfn;
vector<int> e[400005];
int vis[400005], cmp[400005];
int m;

void dfs(int x){
	if(vis[x]) return;
	vis[x] = 1;
	dfn.push_back(x);
	for(auto &i : gph[x]) dfs(i.first);
}

void rdfs(int x, int c){
	if(cmp[x]) return;
	cmp[x] = c;
	for(auto &i : rev[x]) rdfs(i, c);
}


int extended_euclid(int a, int b, int &x, int &y) {
	int xx = y = 0;
	int yy = x = 1;
	while (b) {
		int q = a / b;
		int t = b; b = a%b; a = t;
		t = xx; xx = x - q*xx; x = t;
		t = yy; yy = y - q*yy; y = t;
	}
	return a;
}

int modular_linear_equation_solver(int a, int b, int n) {
	int x, y;
	int g = extended_euclid(a, n, x, y);
	x = (1ll * x*(b / g)) % n;
	x += n;
	x %= n;
	return x;
}


int nanugy(int a, int b){ /// a = b * x
	return modular_linear_equation_solver(b, a, m);
}

vector<pi> dag[400005];
int cnt[400005];
int n, chk[200005];
int nxt[400005], dp[400005];
int pth[400005];

int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		int x;
		scanf("%d",&x);
		chk[x] = 1;
	}
	gph[m].push_back(pi(0, 0));
	nxt[0] = m;
	for(int i=1; i<m; i++){
		nxt[i] = gcd(i, m) + m;
	}
	for(int i=0; i<m; i++){
		gph[i].push_back(pi(nxt[i], i));
	}
	for(int i=1; i<m; i++){
		if(m % i == 0){	
			for(int j=0; j<m/i; j++){
				gph[i+m].emplace_back((1ll * i * j)%m, j);
			}
		}
	}
	for(int i=0; i<2*m; i++){
		for(auto &j : gph[i]){
			rev[j.first].push_back(i);
		}
		if(!vis[i]) dfs(i);
	}
	reverse(dfn.begin(), dfn.end());
	int p = 0;
	for(auto &i : dfn){
		if(!cmp[i]) rdfs(i, ++p);
	}
	for(int i=0; i<2*m; i++){
		e[cmp[i]].push_back(i);
		if(i < m && !chk[i]) cnt[cmp[i]]++;
		for(auto &j : gph[i]){
			if(cmp[i] != cmp[j.first]){
				dag[cmp[i]].push_back(pi(i, j.second));
			}
		}
	}
	int ans = 0, stt = -1;
	for(int i=p; i; i--){
		for(auto &j : dag[i]){
			int nxt = cmp[1ll * j.first * j.second % m];
			if(dp[i] < dp[nxt]){
				dp[i] = dp[nxt];
				pth[i] = nxt;
			}
		}
		dp[i] += cnt[i];
		if(ans <= dp[i]){
			ans = dp[i];
			stt = i;
		}
	}
	vector<int> ansl;
	while(dp[stt]){
		for(auto &j : e[stt]){
			if(j < m && !chk[j]) ansl.push_back(j);
		}
		stt = pth[stt];
	}
	cout << ans << endl;
	for(int i=(int)ansl.size()-2; i>=0; i--){
		ansl[i+1] = nanugy(ansl[i+1], ansl[i]);
	}
	for(auto &i : ansl){
		cout << i << " ";
	}
}