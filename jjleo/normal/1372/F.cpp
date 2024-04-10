#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n;
queue<pair<int, int> > q;
int x, y, xx, yy;
int a[maxn];
int ans[maxn];

int main(){
	scanf("%d", &n);
	q.push({1, n});
	while(!q.empty()){
		int l = q.front().first, r = q.front().second;
		q.pop();
		printf("? %d %d", l, r);
		puts(""), fflush(stdout);
		scanf("%d%d", &x, &y);
		int z = 1;
		while((z << 1) <= y) z <<= 1;
		int j = 0, k = 0;
		for(int i = (l / z + (l % z != 0)) * z;i <= r;i += z){
			if(!a[i]){
				printf("? %d %d", i, i);
				puts(""), fflush(stdout);
				scanf("%d%d", &xx, &yy);
				a[i] = xx;
			}
			if(a[i] == x){
				if(j) k = i;
				else j = i;
			}
		}
		int ll, rr;
		if(!k){
			printf("? %d %d", max(1, j - z + 1), j);
			puts(""), fflush(stdout);
			scanf("%d%d", &xx, &yy);
			if(xx == x){
				ll = j - yy + 1, rr = ll + y - 1; 
			}else{
				printf("? %d %d", j, min(n, j + z - 1));
				puts(""), fflush(stdout);
				scanf("%d%d", &xx, &yy);
				rr = j + yy - 1, ll = rr - y + 1;
			}
		}else{
			printf("? %d %d", max(1, j - z + 1), k);
			puts(""), fflush(stdout);
			scanf("%d%d", &xx, &yy);
			ll = k - yy + 1, rr = ll + y - 1;
		}
		for(int i = ll;i <= rr;i++) a[i] = x;
		if(l <= ll - 1) q.push({l, ll - 1});
		if(rr + 1 <= r) q.push({rr + 1, r});
	}
	printf("!");
	for(int i = 1;i <= n;i++) printf(" %d", a[i]);
	puts(""), fflush(stdout);
}