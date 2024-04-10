#include <bits/stdc++.h>
#define maxn 233

using namespace std;

int t, n, m;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= m;i++) printf("%d", i & 1);puts("");
		for(int i = 2;i < n;i++){
			if(i == 2 || i == n - 1) for(int j = 1;j <= m;j++) printf("0");
			else if(i & 1){
				if(m == 1) printf("1");
				if(m == 2) printf("10");
				else{
					printf("1");
					for(int j = 2;j < m;j++) printf("0");
					printf("1");
				}
			}else for(int j = 1;j <= m;j++) printf("0");
			puts("");
		}
		if(n == 2){
			for(int i = 1;i <= m;i++) printf("0");puts("");
		}else if(n > 2){
			for(int i = 1;i <= m;i++) printf("%d", i & 1);puts("");
		}
		puts("");
	}
}