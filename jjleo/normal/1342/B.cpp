#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
char s[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s", s + 1);
		n = strlen(s + 1);
		bool tag = true;
		for(int i = 2;i <= n;i++){
			if(s[i] != s[i - 1]){
				tag = false;
				break;
			}
		}
		if(tag){
			printf("%s\n", s + 1);
			continue;
		}
		for(int i = 1;i <= n;i++) printf("01");puts("");
	} 
}