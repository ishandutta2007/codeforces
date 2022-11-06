#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int c,d;
		cin >> c >> d;
		if(c==0&&d==0){
			cout << "0\n";
		}
		else if(abs(c)==abs(d)){
			cout << "1\n";
		}
		else if((abs(d-c))%2==1){
			cout << "-1\n";
		}
		else{
			cout << "2\n";
		}
	}
	return 0;
}