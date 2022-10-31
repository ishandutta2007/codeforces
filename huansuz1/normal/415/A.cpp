#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>

using namespace std;

int n,m,x,a[12345],b[12345],s,i,z1,z2,z3,mi=123457;

int main(){
	cin>>n>>m;
	for (int i=0; i<m; i++){
		cin>>x;
		for (int j=x; j<=n; j++)
			if (b[j]==0) b[j]=x;
	}
	for (int i=1; i<=n; i++) {
		cout<<b[i];
		cout<<" "; 
	}
	return 0;
}