#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, m;
char s[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%s", &n, &m, s + 1);
		int last = 0;
		for(int i = 1;i <= n;i++){
			if(s[i] == '0'){
				if(!last) last = i;
			}else{
				if(last){
					if(last == 1){
						for(int j = 1;j <= m;j++){
							if(i - j <= 0) break;
							s[i - j] = '1';
						}
					}else{
						for(int j = 1;j <= m;j++){
							if(last + j - 1 >= i - j) break;
							s[last + j - 1] = s[i - j] = '1';
						}
					}
					
					last = 0;
				}	
			}
		}
		if(last && last != 1){
			for(int i = 1;i <= m;i++){
				if(last + i - 1 > n) break;
				s[last + i - 1] = '1';
			}
		}
		printf("%s\n", s + 1);
	}
}