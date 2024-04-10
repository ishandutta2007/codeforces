#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, a[55];

void solve ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	int ans = 0;
	for(int k=1;k<=49;k++) {
		bool F = false;
		for(int i=1;i<=n;i++) {
			for(int j=i;j<=n;j++) {
				if(a[j] - a[i] == k) F = true;
			}
		}
		if(F) ans++;
	}
	printf("%d\n", ans);
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--) solve();
}