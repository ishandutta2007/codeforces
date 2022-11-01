#include <iostream>
using namespace std;
int main(void){
	int n;
	int date[101];
	int a;
	bool one = true;
	cin >> n;
	for(int i=0; i< n; i++){
		cin >> date[i];
	}
	if(date[0]%2 == date[1]%2){
		for(int i=2; i<n; i++){
			if(date[i]%2 != date[0]%2){
				cout << i+1 << endl;
				break;
			}
		}
	}else{
		if(date[0]%2==date[2]%2){
			cout << 2 << endl;
		}else{
			cout << 1 << endl;
		}
	}
	return 0;
}