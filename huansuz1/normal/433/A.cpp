#include <iostream>

using namespace std;
int n,x,y,z,s,a[1234];
int main (){ 	
	cin>>n;
	if (n == 1) cout << "NO"; else {
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if (a[i] == 200) z++;
		s += a[i];
	}
	if (s%200==0 &&(z!=n||n % 2!=1)) cout << "YES"; else cout << "NO";
}
return 0;
}