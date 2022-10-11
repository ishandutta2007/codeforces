#include <bits/stdc++.h>
using namespace std;
int main(){
	int x,y,n,s=0;
	cin >> x >> y >> n;
	for (int i=0; i<n; i++){
		s+=2*(x+y-2);
		x-=4;
		y-=4;
	}
	cout << s;
	return 0;
}