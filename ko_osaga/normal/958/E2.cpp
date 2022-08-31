#include<bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
const int mod1 = 1e9 + 409;
const int mod2 = 1e9 + 433;
typedef long long lint;
using pi = pair<lint, int>;

int n, k, a[MAXN];
pi dp[MAXN];

void trial(int l){
	for(int i=1; i<=n; i++){
		dp[i] = dp[i-1];
		if(i > 1){
			auto k = dp[i-2];
			k.first += a[i] - a[i-1] - l;
			k.second++;
			dp[i] = min(dp[i], k);
		}
	}
}

int main(){
	scanf("%d %d",&n,&k);
	swap(n, k);
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	sort(a+1, a+n+1);
	int s = 0, e = 1e9;
	while(s != e){
		int m = (s+e+1)/2;
		trial(m);
		if(dp[n].second >= k) e = m-1;
		else s = m;
	}
	trial(s);
	cout << dp[n].first + 1ll * s * k;
}