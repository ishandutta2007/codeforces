#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n;
char s[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s", s + 1);
		n = strlen(s + 1);
		int x = 0, ans = 0;
		for(int i = n;i;i--){
			if(s[i] == 'A'){
				if(x) x--;
				else ans++;
			}else{
				x++;
			}
		}
		ans += x & 1;
		printf("%d\n", ans);
	}
}