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

int n,m,a[12],p;


int main(){
	cin>>n;
	for (int i=1; i<=n; i++) {
		cin>>m;
		a[m]++;	
	}
	if (a[7]!=0 || a[5]!=0) {cout<<-1; return 0;}
	if (a[1]==a[2] && a[4]+a[6]==a[1] && a[1]>0 && a[3]==0) {
		for (int i=1; i<=a[1]; i++)
			if (a[4]>0) {cout<<1<<" "<<2<<" "<<4<<endl; a[4]--; } else cout<<1<<" "<<2<<" "<<6<<endl; 
	}else
	if (a[1]==a[3] && a[3]==a[6] && a[1]>0 && a[4]==0 && a[2]==0) {
		for (int i=1; i<=a[1]; i++)
			cout<<1<<" "<<3<<" "<<6<<endl; 
	}else
	if (a[1]==a[2]+a[3] && a[4]+a[6]==a[1] && a[1]>0 && a[6]>=a[3]) {
		for (int i=1; i<=a[1]; i++)
			if (a[2]>0 && a[4]>0) {cout<<1<<" "<<2<<" "<<4<<endl;a[2]--; a[4]--; } else 
			    if (a[2]>0 && a[6]>0) {cout<<1<<" "<<2<<" "<<6<<endl;a[2]--; a[6]--; } else 
			    	if (a[3]>0 && a[6]>0) {cout<<1<<" "<<3<<" "<<6<<endl;a[3]--; a[6]--; } 
				} else 	cout<<-1;

	 

	return 0;
}