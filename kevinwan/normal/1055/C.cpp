#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int gcd(int a, int b) {
	while (b)a %= b, swap(a, b);
	return a;
}
int main() {
	int la, ra, ta, lb, rb, tb;
	scanf("%d%d%d%d%d%d", &la, &ra, &ta, &lb, &rb, &tb);
	int g = gcd(ta, tb);
	int ans = 0;
	int sft = (lb - la) / g*g;
	rb -= sft, lb -= sft;
	ans = max(ans,  min(ra,rb) - max(la, lb) + 1);
	rb += g, lb += g;
	ans = max(ans, min(ra, rb) - max(la, lb) + 1);
	rb -= 2 * g, lb -= 2 * g;
	ans = max(ans, min(ra, rb) - max(la, lb) + 1);
	printf("%d", ans);
	getchar(); getchar();
}