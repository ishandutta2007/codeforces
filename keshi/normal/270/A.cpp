#include <iostream>
using namespace std;
int main(){
	int n,a[200];
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> a[i];
	}
	for (int i=0; i<n; i++){
		if (360%(180-a[i])){
			cout << "NO";
		}
		else{
			cout << "YES";
		}
		cout << endl;
	}
	return 0;
}