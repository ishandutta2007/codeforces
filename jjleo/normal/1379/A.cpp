#include <bits/stdc++.h>
#define maxn 60

using namespace std;

int T;
int n;
char s[maxn], b[maxn];
char t[maxn] = "abacaba";
bool suc;

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%s", &n, s + 1);
		suc = false;
		for(int i = 1;i + 7 - 1 <= n;i++){
			memset(b, 0, sizeof(b));
			bool tag = true;
			for(int j = 0;j < 7;j++){
				if(s[i + j] == '?'){
					b[i + j] = t[j];
				}else if(s[i + j] != t[j]){
					tag = false;
					break;
				}
			}
			if(!tag) continue; 
			tag = true;
			for(int k = 1;k + 7 - 1 <= n;k++){
				if(k == i) continue;
				for(int l = 0;l < 7;l++){
					if(s[k + l] != t[l] && b[k + l] != t[l]) break;
					if(l == 6) tag = false;
				}
				if(!tag) break;
			}
			if(tag){
				suc = true;
				puts("Yes");
				for(int j = 1;j <= n;j++){
					if(s[j] == '?'){
						if(b[j]) printf("%c", b[j]);
						else printf("z");
					}else{
						printf("%c", s[j]);
					}
				}
				puts("");
				break;
			}
		}
		if(!suc) puts("No");
	}
}