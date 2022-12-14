#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long T;
	cin >> T;
	while(T--){
		long long N, M;
		cin >> N >> M;
		vector<long long> a(N), b(M);
		priority_queue<long long> pq;
		for(long long i = 0; i < N; ++i){
			cin >> a[i]; --a[i];
			pq.push(a[i]);
		}
		for(long long i = 0; i < M; ++i){
			cin >> b[i];
		}
		for(long long i = 0; i < M; ++i){
			long long val = pq.top(); pq.pop();
			pq.push(min(val, i));
		}
		long long ans = 0;
		for(long long i = 0; i < N; ++i){
			ans += b[pq.top()]; pq.pop();
		}
		cout << ans << '\n';
	}
	return 0;
}