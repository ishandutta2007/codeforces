#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<lint, int>;
const int MAXN = 1000005;

lint a[MAXN];

int main(){
	int t; cin >> t;
	while(t--){
		int n, s; scanf("%d %d",&n,&s);
		for(int i=1; i<=n; i++){
			scanf("%lld",&a[i]);
			a[i] += a[i-1];
		}
		int dap = 0;
		int skip = 0;
		for(int i=1; i<=n; i++){
			if(a[i] <= s) dap = i;
		}
		if(dap < n){
		for(int i=dap + 1; i>=1; i--){
			int l = upper_bound(a + 1, a + n + 1, s + a[i] - a[i-1]) - a - 2;
			if(dap < l){
				dap = l;
				skip = i;
			}
		}
		}
		printf("%d\n", skip);
	}
}