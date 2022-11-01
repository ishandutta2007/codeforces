#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

int n;
char s[maxn];

int main(){
	scanf("%d%s", &n, s + 1);
	if(n == 4) return printf("0"), 0;
	int x;
	for(int i = 1;i <= n;i++) if(s[i] == '1'){
		x = i;
		break;
	}
	int y = 0;
	for(int i = x + 1;i <= n;i++) if(s[i] == '0'){
		y = i;
		break;
	}
	if(y == 0){
		for(int i = x;i <= n;i++) printf("1");
		return 0;
	}
	y = n - y + 1;
	int z = 0;
	for(int i = x;i + y - 1 <= n;i++) if(s[i] == '1'){
		if(z == 0){
			z = i;
			continue;
		}
		for(int j = 0;j < y;j++){
			if(s[n - y + 1 + j] == '1') continue;
			if(s[z + j] < s[i + j]){
				z = i;
				break;
			}else if(s[z + j] > s[i + j]){
				break;
			}
		}
	}
	y = n - y + 1;
	for(int i = 0;i < n - x + 1;i++){
		if(i < y - x) printf("%c", s[x + i]);
		else printf("%c", max(s[x + i], s[z + i - (y - x)]));
	}
}