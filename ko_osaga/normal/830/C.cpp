#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<lint, lint> pi;
const int mod = 1e9 + 7;
const int MAXN = 105;

int n;
lint a[MAXN], k;

lint sum(int x){
	lint ans = n;
	for(int i=0; i<n; i++){
		ans += a[i] / x;
	}
	return ans;
}

int main(){
	cin >> n >> k;
	for(int i=0; i<n; i++) cin >> a[i];
	for(int i=0; i<n; i++) k += a[i], a[i]--;
	lint ans = 1;
	for(int i=2; i<=500000; i++){
		if(sum(i) * i <= k) ans = max(ans, 1ll * i);
	}
	lint cur = sum(500000);
	lint prv = 500000;
	while(cur > n){
		lint next_event = 1e9 + 20;
		for(int i=0; i<n; i++){
			int current_event = a[i] / prv;
			if(current_event == 0) continue;
			next_event = min(next_event, 1ll * a[i] / current_event + 1);
		}
		lint endp = min(next_event - 1, k / cur);
		if(endp >= prv) ans = max(ans, endp);
		prv = next_event;
		cur = sum(prv);
	}
	if(k / cur >= prv) ans = max(ans, k/ cur);
	cout << ans;
}