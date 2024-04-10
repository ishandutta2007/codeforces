#include <algorithm>
#include <cstdio>
using namespace std;

bool dif(int x) {
	int cnt[10] = {0};
	while(x) { cnt[x % 10] ++; x /= 10; }
	for(int i = 0; i < 10; i ++) if(cnt[i] >= 2) return 0;
	return 1;
}
int main() {
	int l, r, cnt = 0;
	scanf("%d%d", &l, &r);
	for(int i = l; i <= r; i ++) {
		if(dif(i)) {
			printf("%d\n", i);
			return 0;
		}
	}
	printf("%d\n", -1);
	return 0;
}