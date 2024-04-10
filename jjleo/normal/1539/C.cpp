#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int n;
ll a[maxn], k, x;
vector<ll> v;

int main(){
	scanf("%d%lld%lld", &n, &k, &x);
	for(int i = 1;i <= n;i++) scanf("%lld", &a[i]);
	sort(a + 1, a + 1 + n);
	for(int i = 2;i <= n;i++) v.push_back(max(0ll, a[i] - a[i - 1] - 1) / x);
	sort(v.begin(), v.end());
	int ans = n;
	for(int i = 0;i < v.size();i++){
		if(k - v[i] < 0) break;
		k -= v[i];
		ans--;
	}
	printf("%d", ans);
}