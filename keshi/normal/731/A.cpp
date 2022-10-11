#include <bits\stdc++.h>
using namespace std;
int main(){
	int f=0;
	string a="a",b;
	cin >> b;
	a+=b;
	for (int i=1; i<a.size(); i++){
		f+=min(abs(a[i]-a[i-1]),26-abs(a[i]-a[i-1]));
	}
	cout << f;
	return 0;
}