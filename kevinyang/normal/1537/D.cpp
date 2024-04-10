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
		bool f = false;
		for(int i = 1; i<=30; i+=2){
			if(n==(1<<i))f = true;
		}
		if(f){
			cout << "Bob\n";
			continue;
		}
		if(true){
			if(n%2==0){
				cout << "Alice\n";
			}
			else{
				cout << "Bob\n";
			}
		}
	}

	return 0;
}