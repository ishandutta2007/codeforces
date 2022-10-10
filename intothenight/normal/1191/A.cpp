#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x;
	cin >> x;
	if(x % 4 == 0){
		cout << "1 A";
	}
	else if(x % 4 == 1){
		cout << "0 A";
	}
	else if(x % 4 == 2){
		cout << "1 B";
	}
	else{
		cout << "2 A";
	}
	return 0;
}