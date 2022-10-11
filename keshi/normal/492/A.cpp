#include <bits\stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int i=1;
	while (n-i*(i+1)/2>=0){
		n-=i*(i+1)/2;
		i+=1;
	}
	cout << i-1;
	return 0;
}