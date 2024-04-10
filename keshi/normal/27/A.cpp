#include <iostream>
using namespace std;
int main(){
	int n,b;
	bool a[3010]={0};
	cin >> n;
	while (n--){
		cin >> b;
		a[b-1]=1;
	}
	int i=0;
	while (a[i]){
		i+=1;
	}
	cout << i+1;
}