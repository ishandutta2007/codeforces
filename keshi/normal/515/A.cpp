#include <bits/stdc++.h>
using namespace std;
int main(){
	int x,y,k;
	cin >> x >> y >> k;
	x=abs(x);
	y=abs(y);
	if (x+y<=k && ((x+y)%2)==(k%2)){
		cout << "Yes";
	}
	else{
		cout << "No";
	}
	return 0;
}