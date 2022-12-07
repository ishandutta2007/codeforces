#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 300005;

int n;
ll a[N], sum[N];

int main() {
	scanf("%d", &n);ll ans = 0;
 	for (int i = 0; i < n; i++) {	
    	scanf("%lld", &a[i]);	
     ans += a[i];
	}
	sort(a, a + n);
	for (int i = n - 1; i >= 0; i--)
		sum[i] = a[i] + sum[i + 1];
		
	for (int i = 0; i < n - 1; i++) {
		ans += sum[i];
	}
	printf("%lld\n", ans);
	//system("pause");
	return 0;
}