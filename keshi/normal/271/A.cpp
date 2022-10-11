#include <iostream>
using namespace std;
int main(){
	int n,a[4];
	cin >> n;
	n+=1;
	bool f=1;
	while (f){
		a[0]=n%10;
		a[1]=n/10%10;
		a[2]=n/100%10;
		a[3]=n/1000%10;
		if (a[0]==a[1] || a[0]==a[2] || a[0]==a[3]){
			n+=1;
		}
		else if(a[1]==a[2] || a[1]==a[3]){
			n+=10-a[0];
		}
		else if(a[2]==a[3]){
			n+=100-a[0]-a[1]*10;
		}
		else{
			f=0;
		}
	}
	cout << n;
	return 0;
}