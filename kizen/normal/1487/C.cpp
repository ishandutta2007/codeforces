#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				if(i < j){
					if(n % 2 == 0 && i % 2 && i + 1 == j){
						cout << "0 ";
					}
					else{
						cout << ((j - i + n) % 2 ? 1 : -1) << ' ';
					}
				}
			}
		}
		cout << '\n';
	}
	return 0;
}