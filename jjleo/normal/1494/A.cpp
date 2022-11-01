#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
char s[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s", s + 1);
		n = strlen(s + 1);
		for(int i = 0;i < 8;i++){
			bool tag = false;
			int x = 0;
			for(int j = 1;j <= n;j++){
				if((1 << (s[j] - 'A')) & i){
					x++;
				}else{
					if(!x){
						tag = true;
						break;
					}
					x--;
				}
			}
			if(x) tag = true;
			if(tag){
				if(i == 7) puts("NO");
				continue;
			}
			puts("YES");
			break;
		}
	}
}