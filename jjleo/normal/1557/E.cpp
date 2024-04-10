#include <bits/stdc++.h>

using namespace std;

int t;
char s[20];

void solve(){
	for(int i = 1;i <= 8;i++){
		for(int j = 1;j <= 8;j++){
			printf("%d %d\n", i, j), fflush(stdout);
			scanf("%s", s);
			if(strlen(s) == 4 && s[3] == 'e') return;
			if(s[0] == 'D'){
				if(j < 8){
					printf("%d %d\n", i + 1, j), fflush(stdout);
					scanf("%s", s);
					if(strlen(s) == 4 && s[3] == 'e') return;
				}
				break;
			}
			if(s[0] == 'U' && j > 1) j = 0;
		}
		i++;
		for(int j = 8;j;j--){
			printf("%d %d\n", i, j), fflush(stdout);
			scanf("%s", s);
			if(strlen(s) == 4 && s[3] == 'e') return;
			if(s[0] == 'D'){
				if(j > 1){
					printf("%d %d\n", i + 1, j), fflush(stdout);
					scanf("%s", s);
					if(strlen(s) == 4 && s[3] == 'e') return;
				}
				break;
			}
			if(s[0] == 'U' && j < 8) j = 9;
		}
	}
}

int main(){
	scanf("%d", &t);
	while(t--) solve();
}