#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;
const ll INF = (1LL) << 60;
const int MAXM = 5e3 + 10;

ll a[MAXN], cnt[MAXN], b[MAXN];

int main(){
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j < i; j++)
			cnt[a[i] - a[j]] ++;
	for(int i = 1; i < MAXM; i++)
		if (cnt[i])
			for(int j = 1; j < MAXM; j++)
				b[i + j] += cnt[i] * cnt[j];
	for(int i = 1; i < 2 * MAXM; i++)
		b[i] += b[i-1];
	ll ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j < i; j++)
			ans += (b[a[i] - a[j] - 1]);
	double now = n * (n - 1) / 2;
	now = now * now * now;
//	cout<<ans<<endl;
//	cout<<now<<endl;
	printf("%.20lf\n", ans * 1.0 / now);
	return 0;
}