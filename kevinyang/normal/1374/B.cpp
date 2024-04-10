#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int count = 0;
		while(true){
			if(n%6==0){
				count++;
				n/=6;
			}
			else{
				break;
			}
		}
		while(true){
			if(n%3==0){
				count+=2;
				n/=3;
			}
			else{
				break;
			}
		}
		if(n==1){
			cout << count << "\n";
		}
		else{
			cout << -1 << "\n";
		}
	}
	return 0;
}