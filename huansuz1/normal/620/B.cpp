#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>
using namespace std;

int n,m,x,y,a[1234567],ans;

int main(){
	cin>>x>>y;
	a[0]=6;
	a[1]=2;
	a[2]=5;
	a[3]=5;
	a[4]=4;
	a[5]=5;
	a[6]=6;
	a[7]=3;
	a[8]=7;
	a[9]=6;
	for (int i=x; i<=y; i++) {
		n=i;
		if (a[n]==0) {
			while(n!=0){
				m=n%10;
				n/=10;
				ans+=a[m];
			}
	    } else ans+=a[n];
	}
	cout<<ans;
		



    return 0;             
}