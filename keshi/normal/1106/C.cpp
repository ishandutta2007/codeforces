#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,a[300010];
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> a[i];
	}
	sort(a,a+n);
	long long int f=0;
	if (n%2==0){
		for (int i=0; i<n/2; i++){
			f+=(a[i]+a[n-i-1])*(a[i]+a[n-i-1]);
		}
	}
	else{
		f=(a[0]+a[1]+a[n-1])*(a[0]+a[1]+a[n-1]);
		for (int i=1; i<n/2; i++){
			f+=(a[i+1]+a[n-i-1])*(a[i+1]+a[n-i-1]);
		}
	}
	cout << f;
	return 0;
}