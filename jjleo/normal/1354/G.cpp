#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, k;
char s[maxn];

inline bool check(int l, int r){
	printf("? %d %d\n", r - l + 1, r - l + 1);
	for(int i = 1;i <= r - l + 1;i++) printf("%d ", i);puts("");
	for(int i = l;i <= r;i++) printf("%d ", i);puts("");
	fflush(stdout);
	scanf("%s", s);
	return s[0] != 'E';
}

int main(){
	scanf("%d", &t);
	while(t--){
		mt19937 myrand(time(0));
		scanf("%d%d", &n, &k);
		bool suc = false;
		for(int i = 1;i <= 30;i++){
			printf("? 1 1\n1\n%d\n", (unsigned int)(myrand()) % (n - 1) + 2);
			fflush(stdout);
			scanf("%s", s);
			if(s[0] == 'S'){
				printf("! 1\n"), suc = true;
				fflush(stdout);
				break;
			}
		}
		if(suc) continue;
		int l = 2, r = 2;
		while(1){
			if(check(l, r)) break;
			l = r + 1;
			r = min(r << 1, n);
		}
		int mid;
		while(l < r){
			mid = l + r >> 1;
			if(check(l, mid)) r = mid;
			else l = mid + 1;
		}
		printf("! %d\n", l);
		fflush(stdout);
	}
}