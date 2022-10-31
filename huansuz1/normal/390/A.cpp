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

int n,m,a[1234],b[123],s,l,x,y,p,ss;

int main() {
    cin>>n;
 	for(int i=0; i<n; i++){
 		cin>>x>>y;
 		a[x]=1;
 		b[y]=1;
	}
	for(int i=0; i<101; i++){
		if(a[i])
			l++;
		if(b[i])
			m++;
	}
	cout<<min(l,m);
		return 0;
}