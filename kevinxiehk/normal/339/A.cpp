#include <bits/stdc++.h>
using namespace std;
 
string a; //input string
int b[55]; //digits of numbers excluding all the '+'
int c; //length of the string
int d; //number of digits excluding all the '+'
//number of digits excluding all the '+' = c/2+1
 
int main () {
	cin >> a;
	c = a.length();
	d = c/2+1;
	if(c==1){cout<<a<<endl;return 0;}
	for (int i = c-1; i >= 0; i--) {
		if (a[i] == '1') {
			b[i/2] = 1;
		}
		else if (a[i] == '2') {
			b[i/2] = 2;
		}
		else if (a[i] == '3') {
			b[i/2] = 3;
		}
	}
	
	for  (int j = 1; j < c; ++j) {
        for (int i = 0; i < d; ++i) {
            if (b[i] > b[i+1]) {
                swap(b[i], b[i+1]);
            }
        }
    }
    
    for (int i = 1; i <= d-1; i++) {
    	cout << b[i] << '+';
	}
	cout << b[d] << endl;
}