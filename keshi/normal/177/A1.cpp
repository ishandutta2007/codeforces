#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,a[110][110];
	cin >> n;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cin >> a[i][j];
		}
	}
	int s=0;
	for (int i=0; i<n; i++){
		s+=a[i][(n-1)/2];
		if (i!=(n-1)/2){
			s+=a[(n-1)/2][i];
			s+=a[i][i];
			s+=a[i][n-i-1];
		}
	}
	cout << s;
	return 0;
}