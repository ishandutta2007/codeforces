#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 60010;

int n, s1, s2;
bool tag[N];

int main() {
	scanf("%d", &n);
	int r = n % 4;
	for(int i = r + 1; i <= n; i += 4) {
		tag[i] = tag[i + 3] = 1; s1 += i + i + 3;
	}
	if(r == 2) {
		tag[1] = 1; s1 ++;
	}
	if(r == 3) {
		tag[1] = tag[2] = 1; s1 += 3;
	}
	printf("%d\n", (int) abs(s1 - (n * (n + 1ll) / 2 - s1)));
	int cnt = 0;
	for(int i = 1; i <= n; i ++) if(tag[i]) cnt ++;
	printf("%d", cnt);
	for(int i = 1; i <= n; i ++) if(tag[i]) {
		printf(" %d", i);
	}
	return 0;
}
/*
1, 2 -> 1 & 2 (sum = 3, c = 1)
1, 2, 3 -> 1, 2 & 3 (sum = 6, c = 0)
1, 2, 3, 4 -> 1, 4 & 2, 3 (sum = 10, c = 0) 
1, 2, 3, 4, 5 -> 1, 3, 4 & 2, 5 (sum = 15, c = 1)
*/