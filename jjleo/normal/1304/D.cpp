#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;
int n;
char s[maxn];
int ans[maxn];


int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%s", &n, s + 1);
		int x = 1;
		for(int i = n;i;i--){
			if(s[i - 1] == '<'){
				int j = i;
				for(;j > 1;j--) if(s[j - 1] == '>') break;
				int k = j;
				for(;j <= i;j++) ans[j] = x++;
				i = k;
			}else{
				int j = i;
				for(;j > 1;j--) if(s[j - 1] == '<') break;
				if(j != 1) ++j;
				int k = j;
				for(j = i;j >= k;j--) ans[j] = x++;
				i = k;
				//printf("%d--\n", k);
			}
		}
		for(int i = 1;i <= n;i++) printf("%d ", ans[i]);puts("");
		
		x = n;
		for(int i = n;i;i--){
			if(s[i - 1] == '<' || i == 1) ans[i] = x--;
			else{
				int j = i;
				for(;j > 1;j--) if(s[j - 1] == '<') break;
				int k = j;
				for(;j <= i;j++) ans[j] = x--;
				i = k;
				
			}
		}
		for(int i = 1;i <= n;i++) printf("%d ", ans[i]);puts("");
	}
}