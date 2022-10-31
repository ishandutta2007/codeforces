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

int n,m,a[12],p,k,d,z;


int main(){
	cin>>k>>d;
	if (d==0 && k>1) {cout<<"No solution"; return 0;   }
		for (int i=0; i<d/9; i++) {
			cout<<9;
			z++;
		}
	   	if (d%9>0) {cout<<d%9; z++;  }
	   	for (int i=0; i<k-z; i++)
	   	cout<<0;
		 

	return 0;
}