#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e5 + 10;

int a[N];
long long b[N];
bool leaf[N];
vector<int> con[N];

const ll INF = 2e13;

void dfs(int s = 1, int p = 0){
	int deg = con[s].size() - (s != 1);
	int cnt = 0;
	for(int v : con[s]){
		if(v != p){
			b[v] = min(INF, b[s] * deg);
			dfs(v, s);
			cnt++;
		}
	}
	if(!cnt) leaf[s] = 1;
}
ll lcm(ll a, ll b){
	if(a >= INF || b >= INF) return INF;
	ll k = b / __gcd(a, b);
	if(a >= INF / k) return INF;
	return (a * k);
}

int main(){
	b[1] = 1;
	int n;
	scanf("%d", &n);
	long long X = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		X += a[i];
	}
	for(int i = 1; i < n; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		con[u].push_back(v);
		con[v].push_back(u);
	}
	dfs();
	// x % b[i] == 0
	// x / b[i] <= a[i];
	long long L = 1;
	long long mn = INF;
	for(int i = 1; i <= n; i++){
		if(leaf[i]){
			L = lcm(L, b[i]);
			if(a[i] <= INF / b[i]){
				mn = min(mn, a[i] * b[i]);
			}
		}
	}
	// largest multiple of L, <= mn, X
	long long Y = L * (min(mn, X) / L);
	printf("%lld\n", X - Y);
}