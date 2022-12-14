#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while(T--){
		int M, N;
		cin >> M >> N;
		vector<pair<int, int>> a(N);
		for(int i = 0; i < N; ++i){
			cin >> a[i].second >> a[i].first;
		}
		sort(a.begin(), a.end());
		int last = 1, b = 0, f = 1;
		for(int i = 0; i < N; ++i){
			if(i < N - 1 && a[i].first == a[i + 1].first){
				if(b){
					cout << "NO\n"; f = 0;
					break;
				}
				last = a[i].first + 1; b = 0;
				++i;
			}
			else{
				if(!b){
					last = a[i].first, b = 3 - a[i].second;
				}
				else{
					if((b != a[i].second) != ((a[i].first - last) % 2)){
						cout << "NO\n"; f = 0;
						break;
					}
					last = a[i].first, b = 0;
				}
			}
		}
		if(b && f){
			cout << "NO\n";
			f = 0;
		}
		if(f){
			cout << "YES\n";
		}
	}
	return 0;
}