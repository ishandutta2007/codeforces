// Hydro submission #6245031f1eee9e598396a291@1648689952353
#include<bits/stdc++.h>
using namespace std;
int a[100],n;
int main() {
	int _;
	cin>>_;
	while (_--) {
		cin>>n;
		for (int i=1; i<=n; i++) {
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		int Min=a[2]-a[1];
		for (int i=2; i<n; i++) {
			Min=min(Min,a[i+1]-a[i]);
		}
		cout<<Min<<endl;
	}
	return 0;
}