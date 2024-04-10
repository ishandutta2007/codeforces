#include <bits/stdc++.h>
#define maxn 2086

using namespace std;

const int p = 998244353;

int n;
char s[maxn];
int f[maxn][maxn];
int sum[maxn];

inline int fpow(int x, int y){
	int ans = 1;
	while(y){
		if(y & 1) ans = 1ll * ans * x % p;
		x = 1ll * x * x % p, y >>= 1; 
	}
	return ans;
}

inline void add(int &x, int y){
	x += y;
	if(x >= p) x -= p;
}

int main(){
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for(int i = 1;i <= n;i++) sum[i] = sum[i - 1] + (s[i] == '?');
	for(int len = 2;len <= n;len++){
		for(int i = 1;i + len - 1 <= n;i++){
			int j = i + len - 1;
			if(s[i] != '(') add(f[i][j], f[i + 1][j]);
			if(s[j] != ')') add(f[i][j], f[i][j - 1]);
			if(s[i] != '(' && s[j] != ')') add(f[i][j], (p - f[i + 1][j - 1]) % p);
			if(s[i] != ')' && s[j] != '(') add(f[i][j], (f[i + 1][j - 1] + fpow(2, sum[j - 1] - sum[i])) % p);
			/*for(int ii = 0;ii <= 1;ii++){
				if(s[i] != '?' && s[i] != '(' + ii) continue;
				for(int jj = 0;jj <= 1;jj++){
					if(s[j] != '?' && s[j] != '(' + jj) continue;
					switch(ii + jj * 2){
						case 0:
							add(f[i][j], f[i][j - 1]);
							break;
						case 1:
							add(f[i][j], f[i + 1][j - 1]);
							//add(f[i][j], f[i][j - 1]);
							//add(f[i][j], f[i + 1][j]);
							//add(f[i][j], (p - f[i + 1][j - 1]) % p);
							break;	
						case 2:
							add(f[i][j], (f[i + 1][j - 1] + fpow(2, sum[j - 1] - sum[i])) % p);	
							break;
						case 3:
							add(f[i][j], f[i + 1][j]);
							break;	
					}
				}
			}*/
		}
	}
	printf("%d", f[1][n]);
}