#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 120000; 
LL b[maxn], g[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	LL ans = 0, sum = 0;
	for(int i = 1; i <= n; i += 1){
		cin >> b[i];
		ans += b[i];
	}
	sort(b + 1, b + n + 1);
	ans *= m;
	for(int i = 1; i <= m; i += 1){
		cin >> g[i];
		sum += g[i]; 
	} 
	sort(g + 1, g + m + 1);
	if(g[1] < b[n]){
		cout << -1;
		return 0;
	}
	if(g[1] == b[n]) ans += sum - b[n] * m;
	else{
		ans += sum - b[n] * (m - 1) - b[n - 1];
	}
	cout << ans;
	return 0;
}