#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,a[510],k,f=0;
	cin >> n >> k;
	cin >> a[0];
	for (int i=1; i<n; i++){
		cin >> a[i];
		if (a[i]+a[i-1]<k){
			f+=k-a[i]-a[i-1];
			a[i]=k-a[i-1];
		}
	}
	cout << f << endl;
	for (int i=0; i<n; i++){
		cout << a[i] << ' ';
	}
	return 0;
}