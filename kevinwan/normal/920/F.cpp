#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int d[1000001];
ll bit[300001],k[300001];
set<int> nd;
void u(int a, int b) { for (; a <= 300000; a += a & -a)bit[a] += b; }
ll q(int a) { ll b = 0; for (; a; a -= a & -a)b += bit[a]; return b; }
int main() {
	int i, j,n,qq,a,b,c;
	set<int>::iterator it;
	for (i = 1; i <= 1000000; i++)for (j = i; j <= 1000000; j += i)d[j]++;
	scanf("%d%d",&n, &qq);
	for (i = 1; i <= n; i++) scanf("%d", k + i),u(i,k[i]);
	for (i = 1; i <= n; i++)if (k[i] > 2)nd.insert(i);
	while (qq--) {
		scanf("%d%d%d", &a, &b, &c);
		if (a == 1) {
			for (it = nd.lower_bound(b); 1; ) {
				if (it == nd.end())break;
				if ((*it) > c)break;
				u(*it, d[k[*it]] - k[*it]);
				k[*it] = d[k[*it]];
				if (k[*it] == 1 || k[*it] == 2)nd.erase(it++);
				else it++;
			}
		}
		else {
			printf("%lld\n", q(c) - q(b - 1));
		}
	}
	getchar(); getchar();
}