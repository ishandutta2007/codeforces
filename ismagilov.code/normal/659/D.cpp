#include <bits/stdc++.h>
using namespace std;

int eps = 0.0000000001;



bool ugol(int x1, int y1, int x2, int y2, int x3, int y3){
		if (x1 == x2){
		if ((y1 < y2) && (x3 < x2)) return true;
		if ((y1 > y2) && (x3 > x2))return true;
	}else{
		if ((x1 > x2) && (y3 < y2)) return true;
		if ((x1<x2) && (y3 > y2)) return true;
	}
	return false;
	
}

int main() {
	int n, a, b, x, y, a1, b1;
	int kol = 0;
	cin >> n;
	cin >> x >> y;
	cin >> a1 >> b1;
	int a2 = x;
	int b2 = y;
	int a3 = a1;
	int b3 = b1;
	for (int i = 2; i <= n; i++){
		a = x;
		b = y;
		x = a1;
		y = b1;
		cin >> a1 >> b1;
		if (ugol(a, b, x, y, a1, b1)){
			kol++;
		}
		//cout << ugol(a, b, x, y, a1, b1) << endl;
	}
	if (ugol(x, y, a1, b1, a2, b2)){
		kol++;
		//cout << ugol(x, y, a1, b1, a2, b2) << endl;
	}
	if (ugol(a1, b1, a2, b2, a3, b3)){
		kol++;
		//cout << ugol(a1, b1, a2, b2, a3, b3) << endl;
	}
	cout << min(kol, n-kol);
	// your code goes here
	return 0;
}