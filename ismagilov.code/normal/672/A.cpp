#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	bool prav = true;
	int kol = 0;
	for (int i = 1; kol < n; i++){
		if (i <= 9){
			kol++;
			if (kol == n){
				cout << i;
			}
		}
		if (i > 9 && i < 100){
			kol++;
			if (kol == n){
				cout << i / 10;
			}
			kol++;
			if (kol == n){
				cout << i % 10;
			}
		}
		if (i >= 100 && i < 1000){
			kol++;
			if (kol == n){
				cout << i / 100;
			}
			kol++;
			if (kol == n){
				cout << i / 10 % 10;
			}
			
			kol++;
			if (kol == n){
				cout << i % 10;
			}
		}
	}
	
}