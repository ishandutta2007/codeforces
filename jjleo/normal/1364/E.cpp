#include <bits/stdc++.h>
#define maxn 9048

using namespace std;

int n;
bool vis[maxn];
int mn, id;
int ans[maxn];
int x, y, z;
int cnt = 4269;
int a[maxn];

int main(){
	scanf("%d", &n);
	/*if(n == 3){
		puts("? 1 2"), fflush(stdout), scanf("%d", &x);
		puts("? 1 3"), fflush(stdout), scanf("%d", &y);
		if(x + y == 3){
			printf("! 0 %d %d\n", x, y);
			return 0;
		}
		puts("? 2 1"), fflush(stdout), scanf("%d", &x);
		puts("? 2 3"), fflush(stdout), scanf("%d", &y);
		if(x + y == 3){
			printf("! %d 0 %d\n", x, y);
			return 0;
		}
		puts("? 3 1"), fflush(stdout), scanf("%d", &x);
		puts("? 3 2"), fflush(stdout), scanf("%d", &y);
		if(x + y == 3){
			printf("! %d %d 0\n", x, y);
			return 0;
		}
	}*/
	mn = n << 1;
	x = 1;
	for(int i = 2;i <= n;i++){
		printf("? %d %d\n", x, i), fflush(stdout), scanf("%d", &y), --cnt;
		if(vis[y]){
			memset(vis, 0, sizeof(vis));
			mn = n << 1;
			x = id;
			i--;
		}else{
			vis[y] = true;
			if(y < mn) mn = y, id = i;
		}
	}
	if(x ^ id){
		for(int i = 1;i <= n;i++) a[i] = i;
		random_shuffle(a + 1, a + 1 + n);
		for(int i = 1;i <= n && cnt - 1 >= n - 1;i++){
			if(a[i] == x || a[i] == id) continue;
			//printf("? %d %d\n", x, a[i]), fflush(stdout), scanf("%d", &y), --cnt;
			printf("? %d %d\n", id, a[i]), fflush(stdout), scanf("%d", &z), --cnt;
			/*if(y > z){
				x = id;
				break;
			}*/
			if((z & mn) != mn){
				x = id;
				break;
			}
			/*if((y & mn) != mn){
				break;
			}*/
		}
	}
	for(int i = 1;i <= n;i++){
		if(i ^ x){
			printf("? %d %d\n", x, i);
			fflush(stdout);
			scanf("%d", &ans[i]);
		}
	}
	printf("!");
	for(int i = 1;i <= n;i++) printf(" %d", ans[i]);puts("");
}