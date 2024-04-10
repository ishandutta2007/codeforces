#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
	static char op[20];
	const int a[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
	const int n = 15;
	int cnt = 0, p = 0;
	for(int i = 0; i < n; i ++) {
		printf("%d\n", a[i]);
		fflush(stdout);
		scanf("%s", op);
		if(* op == 'y') {
			cnt ++;
			if(cnt == 1) p = a[i];
			if(cnt >= 2) break ;
		}
	}
	if(cnt == 0) puts("prime");
	else if(cnt >= 2) {
		puts("composite");
	} else if(p * p <= 100) {
		printf("%d\n", p * p);
		fflush(stdout);
		scanf("%s", op);
		if(* op == 'y') puts("composite");
		else puts("prime");
	} else puts("prime");
	fflush(stdout);
	return 0;
}