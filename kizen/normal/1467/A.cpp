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
		for(int i = 0; i < N; ++i){
			if(i == 0){
				cout << 9;
			}
			else if(i == 1){
				cout << 8;
			}
			else{
				cout << (i + 7) % 10;
			}
		}
		cout << '\n';
	}
	return 0;
}