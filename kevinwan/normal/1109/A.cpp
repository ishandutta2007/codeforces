#include<bits/stdc++.h>
#define mid (l+r>>1)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mn = 1 << 20;
ll ap[2][mn];
int main() {
	int n,x,i,cum=0;
	scanf("%d", &n);
	ap[0][cum]++;
	for (i = 1; i <= n; i++)scanf("%d", &x),cum^=x, ap[i%2][cum]++;
	ll ans = 0;
	for (i = 0; i < mn; i++)ans += ap[0][i] * (ap[0][i] - 1) + ap[1][i] * (ap[1][i] - 1);
	printf("%lld", ans>>1);
}