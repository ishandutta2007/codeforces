#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define slld(n) scanf("%lld", &(n))
#define ld long double
const int N = 2e5 + 10;
ll A[N];
ld mx = 1.3e18;
int main(){
	int n;
	ll K;
	scanf("%d %lld", &n, &K);
	vector<int> positive;
	for(int i = 1; i <= n; i++){
		slld(A[i]);
		if(A[i] >= K){
			printf("0\n"); return 0;
		}
		if(A[i] > 0) positive.push_back(i);
	}
	ll lo = 1, hi = 1e18 + 1;
	int len = positive.size();
	while(lo < hi){
		ll mid = (lo + hi) >> 1;
		ll C = 1;
		ld C2 = 1;
		ll sm = 0; ld sm2 = 0;
		int cnt = 0;
		bool ok = 0;
		int j = 1;
		int rem = len;
		ll k = mid;
		for(int i = n; i >= 1; i--){
			sm2 += A[i] * C2;
			if(A[i] != 0) rem--;
			if(sm2 >= mx){
				ok = 1;
				break;
			}
			sm += A[i] * C;
			C2 = (C2 * (k - 1 + j)) / j;
			if(C2 >= mx){
				if(rem) ok = 1;
				break;
			}
			ll ac = C / j, bc = C % j;
			C = ac * (k - 1 + j) + (bc * (k - 1 + j)) / j;
			j++;
		}
		if(sm >= K) ok = 1;
		if(ok) hi = mid;
		else lo = mid + 1;
	}
	printf("%lld\n", lo);
}