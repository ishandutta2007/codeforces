//Author: HeXun
//Date: 09-14-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 120000;
int p[maxn];
int gp(int u){
	return p[u] ? p[u] = gp(p[u]) : u;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n, k, ans = 0;
	cin >> n >> k;
	for(int i = 1; i <= k; i += 1){
		int u, v;
		cin >> u >> v;
		u = gp(u);
		v = gp(v);
		ans += u != v;
		if(u != v) p[u] = v;
	}
	cout << k - ans;
	return 0;
}