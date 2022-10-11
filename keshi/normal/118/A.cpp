#include <iostream>
using namespace std;
int main(){
	string a;
	cin >> a;
	for (int i=0; i<a.size(); i++){
		if (a[i]>='A' and a[i]<='Z'){
			a[i]+=32;
		}
		if (!(a[i]=='a' || a[i]=='o' || a[i]=='u' || a[i]=='i' || a[i]=='e' || a[i]=='y')){
			cout << '.' << a[i];
		}
	}
	return 0;
}