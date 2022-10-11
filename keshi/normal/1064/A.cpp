#include <bits/stdc++.h>
using namespace std;
int main(){
	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	int n = sizeof(a)/sizeof(a[0]); 
    sort(a, a+n); 
	if (a[2]-a[0]+1>a[1]){
		cout << a[2]-a[0]-a[1]+1;
	}
	else{
		cout << 0;
	}
	return 0;
}