#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 200005;

int n;
lint b[MAXN], a[MAXN];

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n/2; i++) scanf("%lld",&b[i]);
	for(int i=2; i<=n/2; i++){
		a[i] = a[i-1] + max(b[i] - b[i-1], 0ll);
	}
	for(int i=1; i<=n/2; i++) a[n+1-i] = b[i] - a[i];
	for(int i=1; i<=n; i++) printf("%lld ", a[i]);
}