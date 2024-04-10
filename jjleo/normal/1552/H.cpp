#include <bits/stdc++.h>

using namespace std;

int f[10];

int main(){
	printf("? 40000 ");
	for(int i = 1;i <= 200;i++) for(int j = 1;j <= 200;j++) printf("%d %d ", i, j);
	puts(""), fflush(stdout);
	scanf("%d", &f[0]);
	int l = 1, r = 7, mid, ans = 0;
	while(l <= r){
		mid = l + r >> 1;
		printf("? %d ", 200 / (1 << mid) * 200);
		for(int i = 1 << mid;i <= 200;i += 1 << mid) for(int j = 1;j <= 200;j++) printf("%d %d ", i, j);
		puts(""), fflush(stdout);
		scanf("%d", &f[mid]);
		if(f[mid] * (1 << mid) == f[0]) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	int n = abs(f[ans] - 2 * f[ans + 1]), m = f[0] / n;
	printf("! %d", 2 * (n + m - 2));
}