#include<bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using lint = long long;
const int MAXN = 1000050;
const int mod = 1e9 + 7;

int n, a[MAXN];

int main(){
	scanf("%d",&n);
	for(int i=0; i<n*2; i++) scanf("%d",&a[i]);
	sort(a, a+2*n);
	lint ans = 1ll * (a[n-1] - a[0]) * (a[2*n-1] - a[n]);
	for(int i=1; i<=n-1; i++){
		ans = min(ans, 1ll * (a[2*n-1] - a[0]) * (a[i+n-1] - a[i]));
	}
	cout << ans << endl;
}