#include <algorithm>
#include <cstdio>
using namespace std;

int a, b, r;

int main() {
	scanf("%d%d%d", &a, &b, &r);
	puts(2 * r <= min(a, b) ? "First" : "Second");
	return 0;
}