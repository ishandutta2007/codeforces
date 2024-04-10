#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,a;
	bool f=0;
	cin >>n;
	while (n--){
		cin >> a;
		if (a==1){
			f=1;
		}
	}
	if (f){
		cout << -1;
	}
	else{
		cout << 1;
	}
	return 0;
}