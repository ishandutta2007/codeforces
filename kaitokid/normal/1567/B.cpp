#include <bits/stdc++.h>
#define F first
#define S second

using namespace std;
typedef long long ll;

const int N = 3e5 + 9;
int xr[300008];
int main () {
	for(int i=1;i<=300005;i++)xr[i]=xr[i-1]^i;
	int t;
	cin >> t;
	while (t--) {
	int a,b;
	cin>>a>>b;
	int u=xr[a-1]^b;
	if(u==0){cout<<a<<endl;continue;}
	if(u==a){cout<<a+2<<endl;continue;}
	cout<<a+1<<endl;
	
	}
	return 0;
	
	
}