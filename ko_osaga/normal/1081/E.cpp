#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 200005;
const int mod = 998244353;

int n, a[MAXN];
int prv[MAXN];

int main(){
	cin >> n;
	for(int i=2; i<=n; i+=2){
		scanf("%d",&a[i]);
	}
	for(int i=2; i<=n; i+=2){
		prv[i] = 2e9;
		for(int j=1; j*j<=a[i]; j++){
			if(a[i] % j == 0){
				int apb = a[i] / j;
				int amb = j;
				if(apb % 2 == amb % 2){
					int r = (apb + amb) / 2;
					int l = (apb - amb) / 2;
					if(prv[i-2] + 1 <= l){
						if(prv[i] > r){
							prv[i] = r;
							prv[i-1] = l;
						}
					}
				}
			}
		}
		if(prv[i] > 1e9){
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	for(int i=1; i<=n; i++) printf("%lld ",1ll * prv[i] * prv[i] - 1ll * prv[i-1] * prv[i-1]);
}