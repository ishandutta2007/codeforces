#include <bits/stdc++.h>

using namespace std;

using LL = long long;
const LL MOD = (LL)1e9 + 7;
const LL NS = (LL)1e5 + 4;
LL N, k;
char s[NS];
LL cnt[64];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> k;
	cin >> (s + 1);
	LL asum = 0;
	for(LL i = 1; i < N - 1; ++i){
		++cnt[s[i] - 'a'];
		asum += (1 << (s[i] - 'a'));
	}
	k -= (1 << (s[N] - 'a'));
	k += (1 << (s[N - 1] - 'a'));
	if((asum + k) % 2){
		cout << "No\n"; return 0;
	}
	k = (asum + k) / 2;
	if(k < 0 || asum < k){
		cout << "No"; return 0;
	}
	LL sum = 0;
	for(LL i = 0; (1ll << i) <= k; ++i){
		sum >>= 1;
		sum += cnt[i];
		if((1ll << i) & k){
			if(!sum){
				cout << "No\n";
				return 0;
			}
			--sum;
		}
	}
	cout << "Yes";
	return 0;
}