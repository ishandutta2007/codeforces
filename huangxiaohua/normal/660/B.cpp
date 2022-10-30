#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[200500],it=1;

int main() {
	cin>>n>>m;
	for(i=n+n+1;i<=m;i++){
		a[it]=i;it+=2;
	}
	it=2;
	for(i=1;i<=min(m,n+n);i++){
		a[it]=i;it+=2;
	}
	for(i=1;i<=10000;i++){
		if(a[i])printf("%d ",a[i]);
	}
}