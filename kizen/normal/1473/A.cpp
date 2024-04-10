#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N, d;
		cin >> N >> d;
		vector<int> a(N);
		for(int i = 0; i < N; ++i){
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		int f = 0;
		for(int i = 0; i < N; ++i){
			if(a[i] > d && a[0] + a[1] > d){
				f = 1;
				break;
			}
		}
		if(f){
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
		}
	}
	return 0;
}