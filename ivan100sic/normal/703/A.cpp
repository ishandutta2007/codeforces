#include "bits/stdc++.h"
using namespace std;

int main(){
	int x, y, n, a=0, b=0;
	cin >> n;
	while (n--){
		cin >> x >> y;
		if (x > y) a++;
		if (x < y) b++;
	}
	
	if (a > b){
		cout << "Mishka" << endl;
	} else if (a < b){
		cout << "Chris" << endl;
	} else {
		cout << "Friendship is magic!^^" << endl;
	}
	return 0;
	
}