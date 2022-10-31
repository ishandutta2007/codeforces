#include <iostream>
using namespace std;
 
int main() {
	int t, n, a, summ = 0;
	cin>>t;
	for(int i = 1; i <= t; i++){
		cin>>n;
		summ = 0;
		for(int i = 0; i < n; i++){
			cin>>a;
			if (a == 1)summ = summ + a;
		}
		if ((summ == 0 && n % 2 == 0) || (summ % 2 == 0 && summ != 0) ) cout<<"YES"<<endl; else cout<<"NO"<<endl;		
	}
}