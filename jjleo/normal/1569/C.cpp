#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

const int p = 998244353;

inline int fpow(int x, int y){
	int ans = 1;
	while(y){
		if(y & 1) ans = 1ll * ans * x % p;
		x = 1ll * x * x % p, y >>= 1;
	}
	return ans;
}

int t, n;
map<int, int> mp;
int x;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		mp.clear();
		for(int i = 1;i <= n;i++) scanf("%d", &x), mp[x]++;
		int mx = mp.rbegin()->first;
		if(mp[mx] == 1 && mp.find(mx - 1) == mp.end()){
			puts("0");
			continue;
		}
		int ans = 1;
		for(int i = 1;i <= n;i++) ans = 1ll * ans * i % p;
		if(mp[mx] == 1) ans = 1ll * ans * (1 + p - fpow(mp[mx - 1] + 1, p - 2)) % p;
		printf("%d\n", ans);
	}
}