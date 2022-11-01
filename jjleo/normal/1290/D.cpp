#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, k;
char s[maxn];
int a[maxn];

int main(){
	scanf("%d%d", &n, &k);
	if(k == 1){
		int ans = 0;
		for(int i = 1;i <= n;i++){
			bool tag = false;
			for(int j = 1;j < i;j++){
				printf("? %d\n", j), fflush(stdout);
				scanf("%s", s);
				printf("? %d\n", i), fflush(stdout);
				scanf("%s", s);
				if(s[0] == 'Y'){
					tag = true;
					break;
				}
			}
			if(!tag) ans++;
		}
		printf("! %d\n", ans), fflush(stdout);
		return 0;
	}
	k /= 2;
	for(int len = 1;len < n / k;len++){
		for(int i = 0;i < len;i++){
			if(i + len >= n / k) break;
			puts("R"), fflush(stdout);
			for(int j = i;j < n / k;j += len){
				for(int l = j * k;l / k == j;l++){
					if(a[l]) continue;
					printf("? %d\n", l + 1), fflush(stdout);
					scanf("%s", s);
					if(s[0] == 'Y') a[l] = 1;
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0;i < n;i++) if(!a[i]) ans++;
	printf("! %d\n", ans), fflush(stdout);
}