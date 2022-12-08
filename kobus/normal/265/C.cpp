#include <iostream>
#include <cmath>

using namespace std;

int v1[1123456],v2[1123456];

int main(){

	string seq;
	cin >> seq;
	int i1=0 , i2=0;

	for ( int q = 0 ; q < seq.size() ; q++ ){

		if ( seq[q] == 'l' ){
			v1[i1] = q+1;
			i1 ++;
		}
		if ( seq[q] == 'r' ){
			v2[i2] = q+1;
			i2 ++;
		}
	}

	for ( int q = 0 ; q < i2 ; q++ ){

		cout << v2[q] << "\n";

	}

	for ( int q = i1 ; q > 0 ; q-- ){

		cout << v1[q-1] << "\n";
	}

	return 0;
}