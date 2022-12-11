#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10;

int n, b[N];
ll a[N];
vector<int> arr[62];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) scanf("%I64d", a + i);
	for(int i = 1; i <= n; i ++) {
		ll x = a[i]; int y = 0;
		while(x % 2 == 0) {
			x /= 2; y ++;
		}
		arr[y].push_back(i);
	}
	int u = 0;
	for(int i = 0; i < 61; i ++)
		if(arr[i].size() > arr[u].size()) u = i;
	for(int i = 0; i < arr[u].size(); i ++) b[arr[u][i]] = 1;
	printf("%d\n", n - (int) arr[u].size());
	for(int i = 1; i <= n; i ++) if(!b[i]) printf("%I64d ", a[i]);
	return 0;
}