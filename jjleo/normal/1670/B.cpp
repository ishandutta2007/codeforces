#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, k;
char s[maxn];
bool tag[26];
char c[20];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%s%d", &n, s + 1, &k);
		memset(tag, 0, sizeof(tag));
		while(k--) scanf("%s", c), tag[c[0] - 'a'] = true;
		int ans = 0, last = 0;
		for(int i = 1;i <= n;i++){
			if(tag[s[i] - 'a']){
				if(i - last > ans){
					ans = i - last;
					if(last == 0) ans--;
				}
				last = i;
			}
		}
		printf("%d\n", ans);
	}
}