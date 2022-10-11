#include <iostream>
using namespace std;
int main(){
	int n,f=0,d,h;
	cin >> n;
	for (int i=0; i<n; i++){
		d=0;
		for (int j=0; j<3; j++){
			cin >> h;
			d+=h;
		}
		if (d>1){
			f+=1;
		}
	}
	cout << f;
	return 0;
}