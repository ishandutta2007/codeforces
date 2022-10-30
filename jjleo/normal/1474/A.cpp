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
		int x;
		for(int i = 1;i <= n;i++){
			if(i == 1){
				printf("1");
				x = s[i] + 1;
				continue;
			}
			if(s[i] + 1 == x) x = s[i], printf("0");
			else x = s[i] + 1, printf("1"); 
		}
		puts("");
	} 
}