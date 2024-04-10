#include <bits/stdc++.h>
using namespace std;

int a, x, y;
string s;


int main(){
	cin >> a;
	cin >> s;
	for (int i = 0; i < a; ++i){
		if (s[i] == '('){
			if (x <= y){
				cout << '0';
				x++;
			}	
			else{
				cout << '1';
				y++;
			}
		}
		if (s[i] == ')'){
			if (x >= y){
				cout << '0';
				x--;
			}	
			else{
				cout << '1';
				y--;
			}	
		}
	}
	return 0;
}