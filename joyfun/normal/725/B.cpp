#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 200005;
char str[N];
long long n;
int sb[10] = {4, 5, 6, 3, 2, 1};

int main() {
	scanf("%s", str);
	int len = strlen(str);
	char c = str[len - 1]; str[len - 1] = 0;
	sscanf(str, "%lld", &n);
	long long ca;
	if (n % 4 == 0) ca = n / 2 - 1;
	if (n % 4 == 2) ca = n / 2;
	if (n % 4 == 3) ca = (n - 1) / 2 - 1;
	if (n % 4 == 1) ca = (n - 1) / 2;
	int bb = 0;
	if (n % 2 && n / 2 % 2) bb = 2;
	if (n % 2 == 0 && n / 2 % 2 == 0) bb = 2;
	printf("%lld\n", ca * 6 + n - 1 - bb + sb[c - 'a']);
	return 0;
}