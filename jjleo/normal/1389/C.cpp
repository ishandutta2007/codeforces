#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;
int n;
char s[maxn];
int ans;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s", s + 1);
		n = strlen(s + 1);
		ans = n - 2;
		for(int i = 0;i < 10;i++){
			for(int j = 0;j < 10;j++){
				int len = 0;
				int sum = 0;
				for(int k = 1;k <= n;k++){
					if(!(len & 1)){
						if(s[k] == i + '0') len++;
						else sum++;
					}else{
						if(s[k] == j + '0') len++;
						else sum++;
					}
				}
				if(i != j && (len & 1)) sum++;
				ans = min(ans, sum);
			}
		}
		printf("%d\n", ans);
	}
}