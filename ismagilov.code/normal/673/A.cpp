#include <bits/stdc++.h>
using namespace std;
 
bool t[91];
 
int main() {
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> m;
		t[m] = true;
	}
	int kol = 0;
	for (int i = 1; i <= 90; i++){
		if (!t[i]){
			kol++;
			if (kol >= 15){
				cout << i;
				return 0;
			}
		}
		else{
			kol = 0;
		}
	}
	cout << 90;
	return 0;
}