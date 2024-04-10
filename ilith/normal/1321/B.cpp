#include<bits/stdc++.h>
using namespace std;
long long n;
long long u;
long long a[2000010];
long long ma;
int main(){
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>u;
		a[u-i+n]+=u;
	}
	for(long long i=0;i<=400000+n+1;i++){
		ma=max(ma,a[i]);
	}
	cout<<ma;
	return 0;
}