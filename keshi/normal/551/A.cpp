#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,a[2010],m;
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> a[i];
	}
	for (int i=0 ; i<n; i++){
		m=1;
		for (int j=0; j<n; j++){
			if (a[j]>a[i]){
				m++;
			}
		}
		cout << m << ' ';
	}
	return 0;
}