#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

const int p = 998244353;

int t;
int n;
char s[maxn];
int inv[maxn];

int main(){
	inv[1] = 1;for(int i = 2;i < maxn;i++) inv[i] = 1ll * (p - p / i) * inv[p % i] % p;
	scanf("%d", &t);
	while(t--){
		scanf("%d%s", &n, s + 1);
		int cnt = 1, x = 0;
		for(int i = 1;i <= n;i++) if(s[i] == '0') cnt++; 
		for(int i = 1;i <= n;i++){
			if(i && s[i] == '1' && s[i - 1] == '1'){
				x++;
				i++;
			}
		}
		int ans = 1;
		for(int i = 1;i <= x;i++) ans = 1ll * ans * (cnt + x - i) % p * inv[i] % p;
		printf("%d\n", ans);
	}
}