#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 200005;
int n;
struct Man {
	int v, id;
	Man() {}
	Man(int v, int id) {
		this->v = v;
		this->id = id;
	}
	bool operator > (Man c) {
		return v > c.v;
	}
	bool operator < (Man c) {
		return v < c.v;
	}
} a[N], b[N];

int an, bn, flag;

int strcm() {
	int i = 0, j = 0;
	while (i < an && j < bn) {
		if (a[i] > b[j]) return 1;
		if (a[i] < b[j]) return -1;
		i++; j++;
	}
	if (an == bn) return 0;
	if (an > bn) return 1;
	return -1;
}

long long suma = 0, sumb = 0;

bool judge() {
	if (suma > sumb) return 0;
	if (suma < sumb) return 1;
	if (strcm() == 0) {
		return flag;
	}
	if (strcm() < 0) return true;
	if (strcm() > 0) return false;
}

int main() {
	scanf("%d", &n);
	int tmp;
	an = bn = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		if (tmp > 0) {
			suma += tmp;
			a[an++] = Man(tmp, i);
			flag = 0;
		}
		else {
			sumb -= tmp;
			b[bn++] = Man(-tmp, i);
			flag = 1;
		}
	}
	if (!judge()) printf("first\n");
	else printf("second\n");
	return 0;
}