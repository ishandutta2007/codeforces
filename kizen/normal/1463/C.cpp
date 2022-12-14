#include <bits/stdc++.h>

using namespace std;

using LL = long long;
const LL MOD = (LL)1e18 + 7;
const LL NS = (LL)1e5 + 4;
LL T, N;
LL A[NS], B[NS];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while(T--){
		cin >> N;
		for(LL i = 1; i <= N; ++i){
			cin >> A[i] >> B[i];
		}
		LL ans = 0, now = 0, to = 0;
		A[N + 1] = MOD;
		for(LL i = 1; i <= N; ++i){
			if(now == to){
				to = B[i];
			}
			LL t = A[i + 1] - A[i];
			if(to >= now){
				if(B[i] >= now && B[i] <= min(now + t, to)){
					++ans;
				}
				now = min(now + t, to);
			}
			else{
				if(B[i] <= now && B[i] >= max(now - t, to)){
					++ans;
				}
				now = max(now - t, to);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}