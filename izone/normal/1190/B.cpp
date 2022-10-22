#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
int n, w[101000];
map<int, int>C;
int c2;
void Add(int a, int b) {
	if (C[a] >= 2)c2--;
	C[a] += b;
	if (C[a] >= 2)c2++;
}
int main() {
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}
	sort(w + 1, w + n + 1);
	long long cur = 0, last = 0;
	for (i = 1; i <= n; i++) {
		cur += w[i];
		last += i - 1;
	}
	for (i = 1; i <= n; i++) {
		Add(w[i], 1);
	}
	int ck = 0;
	for (i = 1; i <= n; i++) {
		if (w[i]) {
			Add(w[i], -1);
			Add(w[i] - 1, 1);
			if (c2 == 0) {
				if ((cur - last) % 2 == 0) {
					puts("cslnb");
				}
				else {
					puts("sjfnb");
				}
				return 0;
			}
			Add(w[i] - 1, -1);
			Add(w[i], 1);
		}
	}
	puts("cslnb");
}