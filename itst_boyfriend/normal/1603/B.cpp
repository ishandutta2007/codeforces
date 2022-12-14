#include<bits/stdc++.h>
using namespace std;

int X , Y , T;

int main(){
	for(cin >> T ; T ; --T){
		cin >> X >> Y;
		if(X > Y) cout << (X + Y) << endl;
		else if(Y % X == 0) cout << Y << endl;
		else{int P = Y % X; cout << Y - (P / 2) << endl;}
	}
	return 0;
}