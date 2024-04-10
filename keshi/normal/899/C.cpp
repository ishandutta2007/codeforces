#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
	cin >> n;
	
	if(n % 2 == 0){
		if(n % 4 == 0){
			cout << 0 << endl << n / 2 << ' ';
			for(int i = 1; i <= n / 4; i++){
				cout << i << ' ' << n - i + 1 << ' ';
			}
		}
		else{
			cout << 1 << endl << n / 2 << ' ';
			for(int i = 1; i <= (n - 2) / 4; i++){
				cout << i << ' ' << n - i + 1 << ' ';
			}
			cout << n / 2;
		}
	}
	else{
		if(n % 4 == 1){
			cout << 1 << endl << n / 2 + 1 << ' ';
			for(int i = 1; i <= n / 4; i++){
				cout << i << ' ' << n - i << ' ';
			}
			cout << n / 2 << ' ';
		}
		else{
			cout << 0 << endl << n / 2 + 1 << ' ';
			for(int i = 1; i <= (n + 1) / 4; i++){
				cout << i << ' ' << n - i << ' ';
			}
		}
	}
	return 0;
}