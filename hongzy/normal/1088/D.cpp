#include <cstdio>
using namespace std;

int qwq(int a, int b) {
	if(a == b) return 0;
	return a < b ? -1 : 1;
}
int tags[40], mark[40];
int ask(int x, int y) {
	printf("? %d %d\n", x, y);
	fflush(stdout);
	scanf("%d", &x);
//	x = qwq(x ^ 3, y ^ 5);
	return x;
}

int main() {
	int tag = ask(0, 0), r1 = 0, r2 = 0, a = 0, b = 0;
	for(int i = 29; i >= 0; i --) {
		tags[i] = ask(r1 | (1 << i), r2 | (1 << i));
		if(tag == -tags[i] && tag) {
			if(tag == -1) b |= 1 << i, r2 |= 1 << i;
			else if(tag == 1) a |= 1 << i, r1 |= 1 << i;
			tag = ask(r1, r2);
		} else mark[i] = 1;
	}
	for(int i = 29; i >= 0; i --) if(mark[i])
		if(ask(r1 | (1 << i), r2) != 1) a |= 1 << i, b |= 1 << i;
	printf("! %d %d\n", a, b);
	fflush(stdout);
	return 0;
}