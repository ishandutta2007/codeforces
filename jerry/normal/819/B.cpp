#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll m[1000005], c[1000005];
int a[1000005], n, ans;

void addline(ll M, ll C, int l, int r)
{
	m[l] += M; c[l] += C;
	m[r] -= M; c[r] -= C;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++) scanf("%d", a+i), a[i]--;
	for (int i = 0;i < n;i++)
	{
		addline(1, -((i-a[i]+n)%n), (i-a[i]+n)%n, min(n, ((i-a[i]+n)%n)+a[i]+1));
		addline(-1, (i-a[i]+n)%n, max(0, ((i-a[i]+n)%n)-n+a[i]+1), (i-a[i]+n)%n);
		addline(1, n-((i-a[i]+n)%n), 0, max(0, ((i-a[i]+n)%n)-n+a[i]+1));
		addline(-1, n+((i-a[i]+n)%n), min(n, ((i-a[i]+n)%n)+a[i]+1), n);
	}
	for (int i = 1;i < n;i++) m[i] += m[i-1], c[i] += c[i-1];
	for (int i = 0;i < n;i++) if (m[i]*i+c[i] < m[ans]*ans+c[ans]) ans = i;
	//for (int i = 0;i < n;i++) fprintf(stderr, "%d: %lld\n", i, m[i]*i+c[i]);
	printf("%lld %d\n", m[ans]*ans+c[ans], (n-ans)%n);
	return 0;
}