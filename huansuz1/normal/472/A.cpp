#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <string>

using namespace std;

int n,k,p,t,q;

int main() {
	cin>>n;
	for (int i=4; i<=n; i++) {
		
		double x=sqrt(i+1.0);
		t=1;
		
		for (int j=2; j<=x; j++)
			if (i % j == 0) {
				t=0; 
				break; 
			}
		
		p=1;
		q=n-i;
		x=sqrt(q+1.0);
		
		for (int j=2; j<=x; j++)
			if (q%j==0) {
				p=0; 
				break; 
			}
		
		if (p+t==0) {
			cout<<i<<" "<<q; 
			break;
		}

	}
	return 0;
}