#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

const int p = 1e9 + 7;

int t;
char s[maxn];
int a[maxn];
int n;
int x;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%s", &x, s + 1);
		n = strlen(s + 1);
		for(int i = 1;i <= n;i++) a[i] = s[i] - '0';
		for(int i = 1;n < x;i++){
			int num = n - i;
			for(int j = 1;j < a[i] && n < x;j++){
				for(int k = 1;k <= num && n < x;k++) ++n, a[n] = a[n - num];
			}
		}
		n = strlen(s + 1);
		for(int i = 1;i <= x;i++){
			//printf("%d--\n", a[i]);
			n = (i + 1ll * (p + n - i) * a[i]) % p;
		}
		printf("%d\n", n);
	} 
}