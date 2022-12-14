#include <bits/stdc++.h>

using namespace std;

using LL = long long;
const LL MOD = (LL)1e9 + 7;
const LL NS = (LL)2e5 + 4;
LL N, M;
LL A[NS], B[NS];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for(LL i = 1; i <= N; ++i){
		cin >> A[i];
	}
	sort(A + 1, A + N + 1);
	LL val = A[N] - A[1];
	for(LL i = 2; i < N; ++i){
		val = __gcd(val, A[N] - A[i]);
	}
	for(LL i = 1; i <= M; ++i){
		cin >> B[i];
		cout << __gcd(A[N] + B[i], val) << ' ';
	}
	return 0;
}