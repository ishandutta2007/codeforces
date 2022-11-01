#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
char s[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%s", &n, s + 1);
		int x = 0, y = 0;
		for(int i = 2;i <= n;i++){
			if(s[i] == s[i - 1]){
				if(s[i] == '1') x++;
				else y++;
			}
		}
		printf("%d\n", max(x, y));
	}
}