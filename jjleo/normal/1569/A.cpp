#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
char s[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%s", &n, s + 1);
		int l = -1, r = -1;
		for(int i = 1;i <= n;i++){
			for(int j = i;j <= n;j++){
				int sum = 0;
				for(int k = i;k <= j;k++){
					if(s[k] == 'a') sum++;
					else sum--;
				}
				if(sum == 0) l = i, r = j;
			}
		}
		printf("%d %d\n", l, r);
	}
}