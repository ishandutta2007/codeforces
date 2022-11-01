#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int q, n, t[maxn], c[maxn];
bool tag;

int main(){
	scanf("%d", &q);
	while(q--){
		scanf("%d", &n);
		tag = true;
		for(int i = 1;i <= n;i++){
			scanf("%d", &t[i]);
			if(i > 1 && t[i] != t[i - 1]) tag = false;
		}
		if(tag){
			printf("1\n");
			for(int i = 1;i <= n;i++) printf("1 ");
			puts("");
			continue;
		}
		if(!(n & 1)){
			printf("2\n");
			for(int i = 1;i <= n;i++) printf("%d ", (i & 1) + 1);
			puts("");
			continue;
		}
		int a = 0;
		tag = false;
		for(int i = 1;i <= n;i++){
			if(i == n){
				if(t[i] == t[1]){
					tag = true;
					a = i;
					break;
				}
			}else{
				if(t[i] == t[i + 1]){
					tag = true;
					a = i;
					break;
				}
			}
		}
		if(tag){
			printf("2\n");
			for(int i = 1;i <= n;i++){
				if(i <= a) printf("%d ", (i & 1) + 1);
				else printf("%d ", (i & 1 ^ 1) + 1);
			}
			puts("");
		}else{
			printf("3\n3 ");
			for(int i = 2;i <= n;i++) printf("%d ", (i & 1) + 1);
			puts("");
			continue;
		}
	}
}