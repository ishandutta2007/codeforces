#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, k, a[N], p[N], v[N], c;
char s[N];
int l[N], r[N];

void rm(int x, int y){
	v[a[x]] = 1;
	s[x] = y + '0';
	l[r[x]] = l[x];
	r[l[x]] = r[x];
}

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++){
		scanf("%d", a + i);
		p[a[i]] = i;
	}
	c = n;
	int wh = 1;
	iota(l, l + N, -1);
	iota(r, r + N, 1);
	while(c){
		int x = p[c];
		int lt = l[x], rt = r[x];
		for(int i = 0; i < k; i++){
			if(!lt) break;
			int nx = l[lt];
			rm(lt, wh);
			lt = nx;
		}
		for(int i = 0; i < k; i++){
			if(rt > n) break;
			int nx = r[rt];
			rm(rt, wh);
			rt = nx;
		}
		rm(x, wh);
		while(v[c]) c--;
		wh = 3 - wh;
	}
	puts(s + 1);
}