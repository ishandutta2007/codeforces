#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	vector<int> cnt((int)1e6 + 4);
	while(T--){
		int N; cin >> N; N *= 2;
		vector<int> a(N);
		for(int i = 0; i < N; ++i){
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		int f = 0;
		for(int i = 0; i < N - 1; ++i){
			for(int j = 0; j < N; ++j){
				cnt[a[j]] = 0;
			}
			priority_queue<int> pq;
			for(int j = 0; j < N; ++j){
				++cnt[a[j]];
				pq.push(a[j]);
			}
			vector<pair<int, int>> ans;
			int sum = a[N - 1] + a[i];
			while(!pq.empty()){
				int top = pq.top(); pq.pop();
				if(!cnt[top]){
					continue;
				}
				if(sum - top >= 0 && cnt[sum - top] >= (top * 2 == sum) + 1){
					--cnt[top]; --cnt[sum - top];
					ans.push_back({top, sum - top});
					sum = top;
				}
				else{
					break;
				}
			}
			if((int)ans.size() == N / 2){
				cout << "YES\n";
				cout << ans[0].first + ans[0].second << '\n';
				for(auto&i:ans){
					cout << i.first << ' ' << i.second << '\n';
				}
				f = 1; break;
			}
		}
		for(int j = 0; j < N; ++j){
			cnt[a[j]] = 0;
		}
		if(!f) cout << "NO\n";
	}
	return 0;
}