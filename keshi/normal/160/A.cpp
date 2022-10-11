#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,a[110],s=0,m=0;
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> a[i];
		s+=a[i];
	}
	sort(a,a+n);
	int i=n-1;
	while (2*m<=s){
		m+=a[i];
		i--;
	}
	cout << n-i-1;
	return 0;
}