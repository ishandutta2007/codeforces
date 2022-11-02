#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, a[100005];

void solve ()
{
	scanf("%d",&n);
	int ans = 0;
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		if(i != 1 && a[i-1] >= a[i]) a[i]++;
		if(a[i-1] < a[i]) ans++;
	}
	printf("%d\n", ans);
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--) solve();
}