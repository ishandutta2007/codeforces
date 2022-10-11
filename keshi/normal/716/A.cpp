#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,c,a,b,f=1;
	cin >> n >> c;
	cin >> a;
	for (int i=1; i<n; i++){
		cin >> b;
		if (b-a>c){
			f=0;
		}
		f++;
		a=b;
	}
	cout << f;
	return 0;
}