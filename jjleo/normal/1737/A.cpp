#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, k;
char s[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%s", &n, &k, s + 1);
		int a[26] = {0};
		for(int i = 1;i <= n;i++) a[s[i] - 'a']++;
		for(int i = 1;i <= k;i++){
			int x = 0;
			while(x < n / k){
				if(a[x] == 0) break;
				a[x]--;
				x++;
			}
			printf("%c", x + 'a');
		}
		puts("");
	}
}