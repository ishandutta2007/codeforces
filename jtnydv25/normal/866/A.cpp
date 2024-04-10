#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int A;
	cin >> A;
	if(A==1){
		cout << "1 1\n 1";
		return 0;
	}
	cout << 2 * (A - 1) << " " << "2\n1 2";
 }