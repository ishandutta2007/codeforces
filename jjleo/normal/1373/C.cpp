#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

int t;
char s[maxn];
int n;
long long ans;
int a;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s", s + 1);
		n = strlen(s + 1);
		int x = 0;
		a = n;
		for(int i = 1;i <= n;i++){
			if(s[i] == '+') x++;
			else x--;
			a = min(a, x);
		}
		if(a < 0) ans = 1ll * (-a + 1) * n;
		else{
			printf("%d\n", n);
			continue;
		}
		x = 0;
		int y = 0;
		for(int i = 1;i <= n;i++){
			if(s[i] == '+') x++;
			else x--;
			if(x < 0 && y > x){
				y = x;
				ans -= n - i;
			}
		}
		printf("%lld\n", ans);
	}
}