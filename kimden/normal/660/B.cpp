#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n,m,i,j;
	cin >> n >> m;
	int a[109]={},b[109]={},c[109]={},d[109]={};
	for(i=1;(i<=m && i<=2*n);i++){
		if(i%2!=0){
			a[(int)((i-1)/2)] = i;
		}else{
			b[(int)((i-1)/2)] = i;
		}
	}
	for(i=2*n+1;(i<=m && i<=4*n);i++){
		if(i%2!=0){
			c[(int)((i-1)/2)-n] = i;
		}else{
			d[(int)((i-1)/2)-n] = i;
		}
	}
	bool space=false;
	for(int i=0;i<n;i++){
		if(c[i]!=0){
			if(space) cout << " ";
			cout << c[i];
			space=true;
		}
		if(a[i]!=0){
			if(space) cout << " ";
			cout << a[i];
			space=true;
		}
		if(d[i]!=0){
			if(space) cout << " ";
			cout << d[i];
			space=true;
		}
		if(b[i]!=0){
			if(space) cout << " ";
			cout << b[i];
			space=true;
		}
	}
}