#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

int n, q, p;
int a[maxn], x, cnt;
char s[maxn];
int l, r;
int f[maxn];

inline void add(int x, int y){
	cnt -= a[x] != 0;
	a[x] = (a[x] + y) % p;
	cnt += a[x] != 0;
}

int main(){
	scanf("%d%d%d", &n, &q, &p);
	f[1] = f[2] = 1 % p;
	for(int i = 3;i <= n;i++) f[i] = (f[i - 1] + f[i - 2]) % p;
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	for(int i = 1;i <= n;i++) scanf("%d", &x), a[i] = (a[i] + p - x) % p;
	for(int i = n;i > 1;i--) a[i] = (1ll * a[i] + p - a[i - 1] + p - a[i - 2]) % p;
	for(int i = 1;i <= n;i++) cnt += a[i] != 0;
	while(q--){
		scanf("%s%d%d", s, &l, &r);
		if(s[0] == 'A'){
			add(l, 1 % p);
			if(r + 1 <= n) add(r + 1, (p - f[r - l] + p - f[r - l + 1]) % p);
			if(r + 2 <= n) add(r + 2, (p - f[r - l + 1]) % p);
		}else{
			add(l, (p - 1) % p);
			if(r + 1 <= n) add(r + 1, (f[r - l] + f[r - l + 1]) % p);
			if(r + 2 <= n) add(r + 2, (f[r - l + 1]) % p);
		}
		puts(cnt ? "NO" : "YES");
	}
}