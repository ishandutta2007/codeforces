#include "bits/stdc++.h"
using namespace std;

string s;
int r, c;

bool ok(int x){
	return 1 <= x && x <= 8;
}

int main(){
	cin >> s;
	r = s[0] - 'a' + 1;
	c = s[1] - '1' + 1;
	
	int o = -1;
	
	for (int a=-1; a<=1; a++){
		for (int b=-1; b<=1; b++){
			if (ok(r+a) && ok(c+b)) o++;
		}
	}

	cout << o;

	return 0;
}