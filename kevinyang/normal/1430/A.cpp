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
		if(n==1||n==2||n==4){
			cout << "-1\n";
		}
		else if(n==7){
			cout << "0 0 1\n";
		}
		else{
			int count = 0;
			while(n%3!=0){
				n-=5;
				count++;
			}
			cout << n/3 << " " << count<< " 0\n";
		}
	}
	return 0;
}