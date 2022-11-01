#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

long long a[4];
int x, y;

int main(){
	for(int i = 1;i <= 3;i++) scanf("%lld", &a[i]);
	puts("First");
	printf("%lld\n", 10000000000ll), fflush(stdout);
	scanf("%d", &x), a[x] += 10000000000ll;
	long long sum = 2 * a[x];
	for(int i = 1;i <= 3;i++) if(x != i) sum -= a[i];
	printf("%lld\n", sum), fflush(stdout);
	scanf("%d", &y), a[y] += sum;
	printf("%lld\n", a[y] - a[x]), fflush(stdout);
}