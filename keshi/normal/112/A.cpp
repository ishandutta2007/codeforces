#include <iostream>
using namespace std;
int main(){
	string a,b;
	cin >> a >> b;
	for (int i=0; i<a.size(); i++){
		if (a[i]<'a'){
			a[i]+=32;
		}
		if (b[i]<'a'){
			b[i]+=32;
		}
	}
	if(a>b){
		cout << 1;
	}
	else if (a<b){
		cout << -1;
	}
	else{
		cout << 0;
	}
	return 0;
}