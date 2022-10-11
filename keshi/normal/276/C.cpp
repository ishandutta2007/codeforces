#include <bits/stdc++.h>
using namespace std;
int main(){
	long long int n,m,a[200010],b[200010]={0},l,r;
	cin >> n >> m;
	for (int i=0; i<n; i++){
		cin >> a[i];
	}
	sort(a,a+n);
	long long int s=0;
	for (int i=0; i<m; i++){
		cin >> l >> r;
		b[l-1]++;
		b[r]--;
	}
	for (int i=1; i<n; i++){
		b[i]+=b[i-1];
	}
	sort(b,b+n);
	for (int i=0; i<n; i++){
		s+=a[i]*b[i];
	}
	cout << s;
	return 0;
}