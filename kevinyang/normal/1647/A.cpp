#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int v = n/3;
		if(n%3==1){
			for(int i = 0; i<v; i++){
				cout << "12";
			}
			cout << "1\n";
		}
		else{
			for(int i = 0; i<v; i++){
				cout << "21";
			}
			if(n%3==2)cout << "2";
			cout << "\n";
		}
	}
	return 0;
}