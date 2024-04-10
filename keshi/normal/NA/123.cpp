#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,x=0,y=0,z=0,b;
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> b;
		x+=b;
		cin >> b;
		y+=b;
		cin >> b;
		z+=b;
	}
	if (x || y || z){
		cout << "NO";
	}
	else{
		cout << "YES";
	}
	return 0;
}