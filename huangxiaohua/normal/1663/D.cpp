#include <bits/stdc++.h>
using namespace std;

int i,j,k,n,m,t,a[666];

int main() {
	ios::sync_with_stdio(0);
	string s;
	cin>>s>>n;
	if(s=="ABC"){
		cout<< ((n<=1999)?"yes":"no") ;
		return 0;
	}
	if(s=="ARC"){
		cout<< ((n<=2799)?"yes":"no") ;
		return 0;
	}
	if(s=="AGC"){
		cout<< ((n>=1200)?"yes":"no") ;
		return 0;
	}
	cout<<"no";
}