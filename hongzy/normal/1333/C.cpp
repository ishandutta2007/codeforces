#include <bits/stdc++.h>
using namespace std;
 
#define ucin ios::sync_with_stdio(0), cin.tie(0)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;
 
const int N = 2e5 + 10;
int n;
ll a[N];
map<ll, ll> Map; 
int main() {
	scanf("%d", &n); ll cnt = 0, up = 0;
	for(int i = 1; i <= n; i ++) {
		scanf("%lld", a + i), a[i] += a[i - 1];
		if(Map[a[i]] || a[i] == 0) {
			up = max(up, Map[a[i]] + 1);
		}
		cnt += i - up;
		Map[a[i]] = i;
	}
	printf("%lld\n", cnt);
	return 0;
}