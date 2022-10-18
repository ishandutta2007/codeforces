#include <iostream>
using namespace std;

bool u[300];

int main() {
	int n;
	int kol = 0;
	int kol1 = 0;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++){
		if (u[s[i]]){
			kol++;
		}
		else{
			u[s[i]] = 1;
		}
	
	}
	if (n > 26){
		cout << -1;
	}
	else{
	cout << kol;
	}
}