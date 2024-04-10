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

long long n,m,a[123],b[123],mi=103,x,y,z;
string s;

int main() {
  	
  	cin>>n>>m;
  	z=1;
  	while(z<m){
  		z*=n;
  		x++;
  	}

  	if (z==m) cout<<"YES"<<endl<<x-1; else cout<<"NO"; 
    return 0;
}