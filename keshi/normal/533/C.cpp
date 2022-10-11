#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll x1, Y1, x2, y2;

int main(){
	cin >> x1 >> Y1 >> x2 >> y2;
	
	if(x1 <= x2 && Y1 <= y2){
		cout << "Polycarp";
		return 0;
	}
	
	
	while((x1 != 0 || Y1 != 0) && (x2 != 0 || y2 != 0)){
		if(x1 < x2){
			if(Y1 > 0){
				Y1--;
			}
			else{
				x1--;
			}
			if(x2 > 0){
				x2--;
			}
			if(y2 > 0){
				y2--;
			}
		}
		else{
			if(x1 > 0){
				x1--;
			}
			else{
				Y1--;
			}
			if(x2 > 0){
				x2--;
			}
			if(y2 > 0){
				y2--;
			}
		}
		if(x1 <= x2 && Y1 <= y2){
			cout << "Polycarp";
			return 0;
		}
	}
	cout << "Vasiliy";
	return 0;
}