#include <iostream>
using namespace std;
int main(){
	int n,t,b,a[1000010]={0},s=0;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> b;
		s+=b;
		a[s]=1;
	}
	for (int i=1; i<=s; i++){
		a[i]+=a[i-1];
	}
	cin >> t;
	while (t--){
		cin >> b;
		cout << a[b-1]+1 << ' ';
	}
	return 0;
}