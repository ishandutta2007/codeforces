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
		vector<int> a(N), b(N);
		int cnt = 0, mx = 0;
		for(int i = 0; i < N; ++i){
			cin >> a[i];
		}
		for(int i = 1; i < N - 1; ++i){
			if((a[i] > a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i - 1] && a[i] < a[i + 1])){
				b[i] = 1;
			}
			cnt += b[i];
		}
		for(int i = 0; i < N; ++i){
			int val = b[i];
			if(i){
				val += b[i - 1];
			}
			if(i + 1 < N){
				val += b[i + 1];
			}
			if(i >= 2 && i + 2 < N){
				if(a[i - 1] < a[i + 1] && a[i - 2] > a[i - 1] && a[i + 2] < a[i + 1]) --val;
				if(a[i - 1] > a[i + 1] && a[i - 2] < a[i - 1] && a[i + 2] > a[i + 1]) --val;
			}
			mx = max(mx, val);
		}
		cout << cnt - mx << '\n';
	}
	return 0;
}