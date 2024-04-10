#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, x;
char s[maxn];
int a[maxn];
int ans;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%s", &n, &x, s + 1);
		for(int i = 1;i <= n;i++){
			if(s[i] == '0') a[i] = 1;
			else a[i] = -1;
			a[i] += a[i - 1];
		}
		ans = 0;
		for(int i = 1;i <= n;i++){
			if(a[i] == x && !a[n]){
				ans = -1;
				break;
			}
			if(!a[n]) continue;
			if((x - a[i]) % a[n] == 0 && (x - a[i]) / a[n] >= 0) ans++;
		}
		if(!x && !a[n]) ans = -1;
		if(!x && a[n]) ans++;
		printf("%d\n", ans);
	}
}