#include <cstdio>
#include <algorithm>

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	puts(std::min(a, b) % 2 ? "Akshat" : "Malvika");
}