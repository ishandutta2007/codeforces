#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

const int p = 1e9 + 7;

int n;
vector<int> d[maxn];
int f[maxn];

int lcm(int x, int y){
	return 1ll * x * y / __gcd(x, y) % p; 
}

int main(){
	scanf("%d", &n);
	for(int i = n;i;i--) for(int j = i;j <= n;j += i) d[j].push_back(i);
	int ans = 0;
	for(int i = 1;i <= n;i++){
		for(auto j : d[i]) f[j] = i / j - 1;
		for(auto j : d[i]) for(auto k : d[j]) if(k ^ j) f[k] -= f[j];
		for(auto j : d[i]) ans = (ans + 1ll * f[j] * lcm(n - i, j)) % p;
	}
	printf("%d", ans);
}