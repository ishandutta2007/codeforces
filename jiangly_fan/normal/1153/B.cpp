#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 120;
int h[maxn][maxn];
int a[maxn], b[maxn];
int main(){
	int n, m, hh;
	cin >> n >> m >> hh;
	for(int i = 1; i <= m; i += 1) cin >> a[i];
	for(int i = 1; i <= n; i += 1) cin >> b[i];
	for(int i = 1; i <= n; i += 1)
		for(int j = 1; j <= m; j += 1) cin >> h[i][j];
	for(int i = 1; i <= n; i += 1)
		for(int j = 1; j <= m; j += 1) if(h[i][j])
			h[i][j] = min(a[j], b[i]);
	for(int i = 1; i <= n; i += 1){
		for(int j = 1; j <= m; j += 1)
			cout << h[i][j] << " ";
		cout << endl;
	}
}