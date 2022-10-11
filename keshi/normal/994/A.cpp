#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,a[10],b[10];
	cin >> n >> m;
	for (int i=0; i<n; i++){
		cin >> a[i];
	}
	for (int i=0; i<m; i++){
		cin >> b[i];
	}
	for (int i=0; i<n; i++){
		for (int j=0 ; j<m; j++){
			if (a[i]==b[j]){
				cout << a[i] << ' ';
				break;
			}
		}
	}
	return 0;
}