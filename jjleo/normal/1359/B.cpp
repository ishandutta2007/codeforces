#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, m, x, y;
char s[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		int ans = 0;
		scanf("%d%d%d%d", &n, &m, &x, &y);
		for(int i = 1;i <= n;i++){
			scanf("%s", s + 1);
			int last = -1;
			for(int j = 1;j <= m;j++){
				if(s[j] == '.'){
					if(j == 1 || s[j - 1] != '.') last = j;
				}else{
					if(last != -1 && j && s[j - 1] == '.'){
						int X = j - 1 - last + 1;
						if(X & 1) X -= 1, ans += x;
						ans += min(X * x, X / 2 * y); 
					}
				}
			}
			if(s[m] == '.'){
				int X = m - last + 1;
				//printf("%d--\n", X);
				if(X & 1) X -= 1, ans += x;
				ans += min(X * x, X / 2 * y); 
			}
		} 
		printf("%d\n", ans);
	}
}