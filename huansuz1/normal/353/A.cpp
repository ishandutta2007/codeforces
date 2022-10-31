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

int n,m,a[123],b[123],mi=103,x,y,z;
string s;

int main() {
  	
  	cin>>n;
  	for (int i=0; i<n; i++){
  		cin>>a[i]>>b[i];
  		if (a[i]%2==1 && b[i]%2==0)x++;
  		if (b[i]%2==1 && a[i]%2==0)y++;
  		if (b[i]%2==1 && a[i]%2==1)z++;
  	}
  	if (x!=0||y!=0){x+=z; y+=z;} else {
  		if (z%2==0) cout<<0; else cout<<-1;
  	return 0;
  	}

  	if (x==0 && y==0 && z%2==0) {cout<<0; return 0;}
  	if ((x+y)%2==0 ) {
  		z=0;
  		while(x%2!=0 && y%2!=0){
  		if (x>0)	{x--;
  			y++;
  			z++;    } else {
  			y--;
  			x++;
  			z++;
  			}
  		}
  		cout<<z;
  	
  	}else cout<<-1;
  	
    return 0;
}