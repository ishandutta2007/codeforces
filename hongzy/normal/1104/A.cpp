#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	printf("%d\n", n);
	for(int i = 1; i <= n; i ++) 
		printf("1%c", " \n"[i == n]);
	return 0;
}