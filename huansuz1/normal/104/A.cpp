#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int n,m,a[123],p,k,d,z;


int main(){
	cin>>n;
	a[1]=4;
	a[2]=4;
	a[3]=4;
	a[4]=4;
	a[5]=4;
	a[6]=4;
	a[7]=4;
	a[8]=4;
	a[9]=4;
	a[10]=15;
	a[11]=4;
	if(n<=10) cout<<0; else cout<<a[n-10];	

	return 0;
}