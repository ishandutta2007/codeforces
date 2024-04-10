#include <iostream>
using namespace std;
int main(){
	string s;
	cin >> s;
	string a[60];
	for (int i=0; i<s.size(); i+=2){
		a[i/2]=s[i];
	}
	for (int i=s.size()/2; i>-1; i--){
		for (int j=0; j<i; j++){
			if (a[j]>a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	for (int i=0; i<=s.size()/2; i++){
		cout << a[i];
		if (i!=s.size()/2){
			cout << "+";
		}
	}
	return 0;
}