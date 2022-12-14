#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		vector<int> cnt(3);
		for(int i = 0; i < N; ++i){
			int in; cin >> in;
			++cnt[in];
		}
		int tot = cnt[1] + cnt[2] * 2;
		if(tot % 2){
			cout << "NO\n";
			continue;
		}
		tot /= 2;
		int f = 0;
		for(int i = 0; i <= cnt[1]; ++i){
			int val = tot - i;
			if(val % 2 == 0 && cnt[2] * 2 >= val){
				f = 1;
				break;
			}
		}
		cout << (f ? "YES\n" : "NO\n");
	}
	return 0;
}