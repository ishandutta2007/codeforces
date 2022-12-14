#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long T;
	cin >> T;
	while(T--){
		long long N;
		cin >> N;
		priority_queue<long long> pq[2];
		for(long long i = 0; i < N; ++i){
			long long in; cin >> in;
			pq[in % 2].push(in);
		}
		vector<long long> sum(2);
		for(long long i = 0; i < N; ++i){
			long long now = i % 2;
			if(!(long long)pq[now].size() || ((long long)pq[1 - now].size() && pq[1 - now].top() > pq[now].top())){
				pq[1 - now].pop();
			}
			else{
				sum[now] += pq[now].top();
				pq[now].pop();
			}
		}
		if(sum[0] > sum[1]){
			cout << "Alice\n";
		}
		else if(sum[0] < sum[1]){
			cout << "Bob\n";
		}
		else{
			cout << "Tie\n";
		}
	}
	return 0;
}