#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

char a[12][12];
int b[12],p,z;


int main(){
    for (int i=1;i<=8; i++) {
    	for (int j=1; j<=8; j++)  
    		cin>>a[i][j];

    	if (a[i][1]=='B') {
    		p=0;
    		for (int j=1; j<=8; j+=2)
    			if (a[i][j]!='B' || a[i][j+1]=='B') {p=1; break;}
    		if (p==0) z++;
    	}
    	if (a[i][1]=='W') {
    		p=0;
    		for (int j=1; j<=8; j+=2)
    			if (a[i][j]!='W' || a[i][j+1]=='W') {p=1; break;}
    		if (p==0) z++;
    	}
    		   
    	}
    	if (z==8) cout<<"YES"; else cout<<"NO";

		
	return 0;
}