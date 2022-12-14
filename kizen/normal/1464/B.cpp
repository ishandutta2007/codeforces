#include <bits/stdc++.h>

using namespace std;

using LL = long long;
const LL MOD = (LL)1e18 + 7;
const LL NS = (LL)1e5 + 4;
LL N;
char s[NS];
LL x, y;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> (s + 1);
	N = strlen(s + 1);
	cin >> x >> y;
	LL ans = MOD;
	LL sum = 0, one = 0;
	for(LL i = 1; i <= N; ++i){
		if(s[i] == '0'){
			sum += one * y;
		}
		else{
			sum += (i - 1 - one) * x;
		}
		one += (s[i] != '0');
	}
	ans = min(ans, sum);
	LL lone = 0, rone = one;
	for(LL i = 1; i <= N; ++i){
		rone -= (s[i] != '0');
		if(s[i] == '?'){
			sum -= (i - 1 - lone) * x;
			sum -= (N - i - rone) * y;
			sum += lone * y;
			sum += rone * x;
		}
		ans = min(ans, sum);
		lone += (s[i] == '1');
	}
	reverse(s + 1, s + N + 1);
	swap(x, y);
	sum = one = lone = rone = 0;
	for(LL i = 1; i <= N; ++i){
		if(s[i] == '0'){
			sum += one * y;
		}
		else{
			sum += (i - 1 - one) * x;
		}
		one += (s[i] != '0');
	}
	rone = one;
	ans = min(ans, sum);
	for(LL i = 1; i <= N; ++i){
		rone -= (s[i] != '0');
		if(s[i] == '?'){
			sum -= (i - 1 - lone) * x;
			sum -= (N - i - rone) * y;
			sum += lone * y;
			sum += rone * x;
		}
		ans = min(ans, sum);
		lone += (s[i] == '1');
	}
	cout << ans;
	return 0;
}