#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
char s[maxn];
int x;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%s", &n, s + 1);
		x = 0;
		int ans = 0;
		for(int i = 1;i <= n;i++){
			if(s[i] == '(') x++;
			else{
				if(x) x--;
				else ans++;
			}
		}
		printf("%d\n", ans);
	}
}