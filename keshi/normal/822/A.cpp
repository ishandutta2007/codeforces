#include <iostream>
using namespace std;
int main(){
	int a,b;
	cin >> a >> b;
	a=min(a,b);
	long long int s=1;
	for (int i=2; i<=a; i++){
		s*=i;
	}
	cout <<s;
	return 0;
}