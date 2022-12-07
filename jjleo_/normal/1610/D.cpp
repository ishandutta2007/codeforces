#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

const int p = 1e9 + 7;

int n;
int pw[maxn];
int a[maxn];

int main(){
	scanf("%d", &n);
	pw[0] = 1;for(int i = 1;i <= n;i++) pw[i] = (pw[i - 1] + pw[i - 1]) % p;
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	int ans = 0;
	bool tag = false;
	while(n){
		int m = 0;
		for(int i = 1;i <= n;i++) if(!(a[i] & 1)) a[++m] = a[i] / 2;
		if(!tag) ans = (1ll * ans + pw[n] - pw[m]) % p;
		else if(m < n) ans = (ans + 1ll * (pw[n - m - 1] + p - 1) * pw[m]) % p;
		n = m;
		//printf("%d---\n", ans);
		tag = true;
	}
	printf("%d", ans);
}