#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;
const int MAXN = 500005;

int n, k, a[100005];

int main(){
	scanf("%d %d",&n,&k);
	for(int i=0; i<n; i++) scanf("%d",&a[i]);
	sort(a, a+n);
	for(int i=1; i<n; i++){
		a[i] -= a[0];
	}
	lint ans = 0;
	for(int i=1; i<n; i++){
		if(a[i] % k != 0){
			puts("-1");
			return 0;
		}
		ans += a[i] / k;
	}
	cout << ans;
}