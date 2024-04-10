#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,d,a,s;
	cin >> n >> d;
	s=(n-1)*10;
	for (int i=0; i<n; i++){
		cin >> a;
		s+=a;
	}
	if(s>d){
		cout << -1;
	}
	else{
		cout << (n-1)*2+(d-s)/5;
	}
	return 0;
}