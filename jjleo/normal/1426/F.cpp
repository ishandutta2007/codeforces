#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

const int p = 1e9 + 7;

int n;
char s[maxn];
int f[maxn][3];
int ans, x, y, z = 1;

int main(){
	scanf("%d%s", &n, s + 1);
	for(int i = 1;i <= n;i++){
		if(s[i] == 'c'){
			ans = (ans + y) % p;
		}
		if(s[i] == 'b'){
			y = (y + x) % p;
		}
		if(s[i] == 'a'){
			x = (x + z) % p;
		}
		if(s[i] == '?'){
			int X = x, Y = y;
			ans = 1ll * ans * 3 % p, x = 1ll * x * 3 % p, y = 1ll * y * 3 % p;
			ans = (ans + 1ll * Y) % p;
			y = (y + 1ll * X) % p;
			x = (x + z) % p;
			z = 1ll * z * 3 % p;
		}
		//printf("%d %d %d--\n", x, y, ans);
	}
	printf("%d", ans);
}