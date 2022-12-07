#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;

int main() {
	while (~scanf("%d", &n)) {
		int a, b;
		int cnt = 0;
		while (n--) {
			scanf("%d%d", &a, &b);
			if (a > b) cnt++;
			if (a < b) cnt--;
		}
		if (cnt > 0) printf("Mishka\n");
		else if (cnt == 0) printf("Friendship is magic!^^\n");
		else printf("Chris\n");
	}
	return 0;
}