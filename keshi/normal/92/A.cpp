#include <iostream>
using namespace std;
int main(){
	int a,n,i=1;
	cin >> a >> n;
	while (n>=i){
		n-=i;
		i+=1;
		if (i>a){
			i=1;
		}
	}
	cout << n;
	return 0;
}