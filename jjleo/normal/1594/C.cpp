#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

int t, n;
char s[maxn], c[10];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%s%s", &n, c, s + 1);
		int cnt = 0;
		for(int i = 1;i <= n;i++) cnt += s[i] == c[0];
		if(cnt == n){
			puts("0");
			continue;
		}
		bool tag = false;
		for(int i = 2;i <= n;i++){
			bool flag = false;
			for(int j = i;j <= n;j += i){
				if(s[j] != c[0]){
					flag = true;
					break;
				}
			}
			if(!flag){
				printf("1\n%d\n", i);
				tag = true;
				break; 
			}
		}
		if(!tag) printf("2\n%d %d\n", n - 1, n);
	}
}