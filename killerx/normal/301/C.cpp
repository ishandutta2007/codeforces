#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int main() {
	rep(i, 10) printf("???%d>>%d???\n", i, i);
	printf("???>>??\n");
	rep(i, 9) printf("%d??<>%d\n", i, i + 1);
	printf("9??>>??0\n");
	printf("??<>1\n");
	printf(">>???\n");
	return 0;
}