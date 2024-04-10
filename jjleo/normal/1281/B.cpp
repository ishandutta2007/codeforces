#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int T;
char s[maxn], t[maxn];
int n, m;
char x;
int y;

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%s%s", s + 1, t + 1);
		n = strlen(s + 1), m = strlen(t + 1);
		bool tag = false;
		if(strcmp(s + 1, t + 1) < 0){
			tag = true;
		}else{
			for(int i = 1;i <= n && i <= m;i++){
				x = 127, y = 0;
				for(int j = i + 1;j <= n;j++){
					if(s[j] <= x) x = s[j], y = j;
				}
				if(y){
					swap(s[i], s[y]);
					if(strcmp(s + 1, t + 1) < 0){
						tag = true;
						break;
					}
					swap(s[i], s[y]);
				}
			}
		}
		if(!tag) puts("---");
		else printf("%s\n", s + 1);
	}	
}