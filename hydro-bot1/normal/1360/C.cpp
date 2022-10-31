// Hydro submission #6245033d1eee9e598396a315@1648689981405
#include<bits/stdc++.h>
using namespace std;
int a[10000],n;
int main() {
	int _;
	cin>>_;
	while (_--) {
		cin>>n;
		int A=0,B=0;
		for (int i=1; i<=n; i++) {
			cin>>a[i];
			if (a[i]%2==0) {
				A++;
			} else {
				B++;
			}
		}
		if (A%2==0&&B%2==0) {
			cout<<"YES"<<endl;
			continue;
		}
		bool b=0;
		sort(a+1,a+n+1);
		for (int i=1; i<n; i++) {
			if (a[i]+1==a[i+1]) {
				cout<<"YES"<<endl;
				b=1;
				break;
			}
		}
		if (b==0) cout<<"NO"<<endl;
	}
	return 0;
}