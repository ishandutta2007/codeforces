#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int MAXN = 100005;

int n, l, a[MAXN];

int main(){
	cin >> n >> l;
	for(int i=0; i<n; i++) cin >> a[i];
	for(int i=1; i<n; i++) a[i] = min(a[i], a[i-1] << 1);
	lint dap = 1e18;
	for(int i=0; i<n; i++){
		int nl = (l + (1<<i) - 1) >> i;
		lint ans = 0;
		for(int j=n-1; j>=i; j--){
			int p = j - i;
			ans += 1ll * (nl >> p) * a[j];
			nl &= (1 << p) - 1;
		}
		dap = min(dap, ans);
	}
	cout << dap;
}