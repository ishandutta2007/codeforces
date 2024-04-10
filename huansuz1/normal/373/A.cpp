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

int n,m,b[12],p;
char a[12][12];

int main(){
	cin>>n;
	for (int i=1; i<=4; i++)
	    for (int j=1; j<=4; j++){
	    	cin>>a[i][j];
	    	if (a[i][j]!='.')b[a[i][j]-'0']++;	                     
	   	}
	for (int i=1; i<=9; i++)
		if (b[i]>2*n) p=1;

	if (p==1)	cout<<"NO"; else cout<<"YES";
	     
	
	return 0;
}