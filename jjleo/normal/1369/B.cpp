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
		int a = 0, cnt = 0;
		bool tag = false;
		for(int i = 1;i <= n;i++){
			if(!a && s[i] == '0'){
				printf("0");
				continue;
			}
			a = 1;
			if(s[i] == '1'){
				cnt++;
			}else{
				if(cnt && !tag){
					tag = true;
					printf("0");
				}
				cnt = 0;
			}			
		}
		for(int i = 1;i <= cnt;i++) printf("1");
		puts("");
	}
}