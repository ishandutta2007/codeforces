#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int x;
		cin >> x;
		if(x%4==0){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}