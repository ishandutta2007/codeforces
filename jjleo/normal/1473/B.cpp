#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int q;
char s[maxn], t[maxn];
int n, m;

int main(){
	scanf("%d", &q);
	while(q--){
		scanf("%s%s", s + 1, t + 1);
		n = strlen(s + 1), m = strlen(t + 1);
		bool tag = false;
		for(int i = 1;i <= min(n, m);i++){
			if(s[i] != t[i]) break;
			if(n % i || m % i) continue;
			bool flag = false;
			for(int j = i + 1;j <= n;j++){
				if(s[j] != s[j - i]){
					flag = true;
					break;
				}
			}
			for(int j = i + 1;j <= m;j++){
				if(t[j] != t[j - i]){
					flag = true;
					break;
				}
			}
			if(flag) continue;
			tag = true;
			for(int j = n / i * m / i / __gcd(n / i, m / i);j;j--){
				for(int k = 1;k <= i;k++) printf("%c", s[k]);
			}
			puts("");
			break;
		}
		if(!tag) puts("-1");
	}
}