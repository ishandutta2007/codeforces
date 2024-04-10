#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

typedef unsigned long long ull;

int n;
int p[maxn], cnt, f[maxn];
bool tag[maxn];
ull pw[maxn];
int g[maxn], h[maxn];
map<ull, int> mp;

int main(){
	scanf("%d", &n);
	pw[0] = 1;for(int i = 1;i <= n;i++) pw[i] = pw[i - 1] * 131;
	for(int i = 2;i <= n;i++){
		if(!tag[i]) p[++cnt] = i, f[i] = i;
		for(int j = 1;j <= cnt && p[j] * i <= n;j++){
			tag[p[j] * i] = true, f[p[j] * i] = p[j];
			if(i % p[j] == 0) break;
		}
	}
	for(int i = 2;i <= n;i += 2){
		int x = i;
		while(x ^ 1) g[f[x]] ^= 1, x /= f[x];
	}
	if(n & 1){
		for(int i = 1;i <= n;i++){
			int x = i;
			while(x ^ 1) g[f[x]] ^= 1, x /= f[x];
		}
	}
	ull sum = 0;
	for(int i = 1;i <= n;i++) sum += g[i] * pw[i];
	if(!sum){
		printf("%d\n", n);
		for(int i = 1;i <= n;i++) printf("%d ", i);
		return 0;
	}
	ull val = 0;
	for(int i = 1;i <= n;i++){
		int x = i;
		while(x ^ 1){
			h[f[x]] ^= 1;
			if(h[f[x]]) val += pw[f[x]];
			else val -= pw[f[x]];
			x /= f[x];
		}
		if(sum == val){
			printf("%d\n", n - 1);
			for(int j = 1;j <= n;j++) if(i ^ j) printf("%d ", j);
			return 0;
		}
	}
	val = 0;
	for(int i = 1;i <= n;i++) h[i] = 0;
	for(int i = 1;i <= n;i++){
		int x = i;
		while(x ^ 1){
			g[f[x]] ^= 1;
			if(g[f[x]]) sum += pw[f[x]];
			else sum -= pw[f[x]];
			h[f[x]] ^= 1;
			if(h[f[x]]) val += pw[f[x]];
			else val -= pw[f[x]];
			x /= f[x];
		}
		if(mp.find(sum) != mp.end()){
			int ii = mp[sum];
			printf("%d\n", n - 2);
			for(int j = 1;j <= n;j++) if((i != j) && (ii != j)) printf("%d ", j);
			return 0;
		}
		mp[val] = i;
	}
	printf("%d\n", n - 3);
	for(int i = 1;i <= n;i++) if(i != 2 && i != n / 2 && i != n) printf("%d ", i);
	return 0;
}