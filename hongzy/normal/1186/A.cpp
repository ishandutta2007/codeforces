#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	puts(n <= m && n <= k ? "Yes" : "No");
	return 0;
}