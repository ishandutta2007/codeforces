//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const ll mod = 1e9 + 7;
int n, r, c, p[1000100][20];
string s[1000100];
int main() { //DINIC ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> r >> c;
	for(int i = 1; i <= n; i++) cin >> s[i];
	p[n+1][0] = n+1;
	int j = -1;
	ll sm = 0;
	for(int i = 1; i <= n; i++) {
		if(j<i-1) {
			j = i-1;
			sm = 0;
		}
		while(j<n&&sm+(j+1>i)+s[j+1].size()<=c) sm+=(j+1>i)+s[++j].size();//, cout << sm << " ";
		p[i][0] = j+1;
//		cout << i << " " << j << " " << s[i].size() << "\n";
		sm-=s[i].size()+(j>i);
	}
	for(int i = 1; i < 20; i++)
		for(int j = 1; j <= n+1; j++)
			p[j][i] = p[p[j][i-1]][i-1];
	int u = 1, a =0;
	for(int i = 1; i <= n; i++) {
		int x = i;
		for(int j = 20; j--;) if((r>>j)&1) x = p[x][j];
		if(x-i>a)a=x-i,u=i;
	}
//	cout << a << "\n";
	for(int i = 0; i < r; i++) {
		if(p[u][0]==u) break;
		int B = p[u][0];
		for(; u!=B;u++)
			cout << s[u] << (u+1!=B?" ":"\n");
	}
}