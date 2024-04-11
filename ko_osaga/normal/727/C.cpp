#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

int query(int x, int y){
	printf("? %d %d\n", x, y);
	fflush(stdout);
	int ret; scanf("%d",&ret);
	return ret;
}

int n, a[100005];

int main(){
	scanf("%d",&n);
	int p = query(1, 2);
	int q = query(1, 3);
	int r = query(2, 3);
	a[1] = (p + q + r) / 2 - r;
	a[2] = (p + q + r) / 2 - q;
	a[3] = (p + q + r) / 2 - p;
	for(int i=4; i<=n; i++){
		a[i] = query(1, i) - a[1];
	}
	printf("!");
	for(int i=1; i<=n; i++){
		printf(" %d", a[i]);
	}
	fflush(stdout);
}