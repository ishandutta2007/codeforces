#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, k;
int siz[maxn];
int c, x;
int id[maxn];
int mx;

char s[maxn];

inline int get(int l, int r){
	printf("? %d", r - l + 1), fflush(stdout);
	for(int i = l;i <= r;i++) printf(" %d", i), fflush(stdout);puts("");
	fflush(stdout);
	int x;
	scanf("%d", &x);
	return x;
}


int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		for(int i = 1;i <= k;i++) siz[i] = 0;
		for(int i = 1;i <= n;i++) id[i] = 0;
		for(int i = 1;i <= k;i++){
			scanf("%d", &c);
			while(c--){
				scanf("%d", &x);
				id[x] = i;
				siz[i]++;
			}
		}
		mx = get(1, n);
		int l = 1, r = n, mid;
		while(l < r){
			mid = l + r >> 1;
			x = get(l, mid);
			if(x == mx) r = mid;
			else l = mid + 1;
		}
		if(!id[l]) x = mx;
		else{
			printf("? %d", n - siz[id[l]]), fflush(stdout);
			for(int i = 1;i <= n;i++) if(id[i] != id[l]) printf(" %d", i), fflush(stdout);puts("");
			fflush(stdout);
			scanf("%d", &x);
		}
		printf("!"), fflush(stdout);
		for(int i = 1;i <= k;i++){
			if(i == id[l]) printf(" %d", x);
			else printf(" %d", mx);
			fflush(stdout);
		}
		puts("");
		fflush(stdout);
		scanf("%s", s);
		if(s[0] == 'I') return 0;
	}
}