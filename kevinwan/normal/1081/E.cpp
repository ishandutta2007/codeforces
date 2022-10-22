#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
ll k[300000],sq[300000];
vector<int> pre[200001],part[200001];
void die() { printf("No"); exit(0); }
int main()
{
	int n,i,j;
	scanf("%d", &n);
	for (i = 0; i < n / 2; i++)scanf("%lld", k + (2 * i + 2));
	for (i = 1; i*i <= 200000; i++) {
		for (j = i * i; j <= 200000; j += i) {
			if((j/i-i)%2==0)pre[j].push_back(((j / i) - i)/2),part[j].push_back(((j / i) + i) / 2);
		}
	}
	memset(sq, 0x3f, sizeof(sq));
	sq[0] = 0;
	for (i = 2; i <= n; i += 2) {
		for (j = 0; j < pre[k[i]].size(); j++) {
			int po = pre[k[i]][j];
			int ot = part[k[i]][j];
			if (po > sq[i - 2]) {
				if (ot < sq[i])sq[i] = ot, sq[i - 1] = po;
			}
		}
	}
	for (i = 0; i <= n; i++)if (sq[i] == 0x3f3f3f3f3f3f3f3f)die();
	printf("Yes\n");
	for (i = 1; i <= n; i++)printf("%lld ", sq[i] * sq[i] - sq[i - 1] * sq[i - 1]);
	getchar(); getchar();
}