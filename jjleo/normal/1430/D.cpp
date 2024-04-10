#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;
int n;
char s[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%s", &n, s + 1);
		int cnt = 0, x = 0, y = 0;
		for(int i = 1;i <= n;i++){
			if(s[i] != s[i - 1]){
				cnt++;
				if(x > 1) y += min(x - 1, cnt - 1);
				y = min(y, cnt - 1);
				x = 0;
			}
			x++;
		}
		if(x > 1) y += min(x - 1, cnt);
		y = min(y, cnt);
		//printf("%d--\n", y);
		if(y >= cnt){
			printf("%d\n", cnt);
		}else{
			printf("%d\n", y + (cnt - y + 1) / 2);
		}
	}
}