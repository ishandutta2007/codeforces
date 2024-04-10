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

int n,a,b,c,z1,z2,z3,p,d[12],ma;

int main() {
	cin>>n>>d[0]>>d[1]>>d[2];
	sort(d,d+3);
	a=d[0];
	b=d[1];
	c=d[2];
	z1=n/a;
	z2=n/b;
	z3=n/c;
	for (int i=0; i<=z1; i++)
		for (int j=0; j<=z2; j++) {
			int x=n-((i*a)+(j*b));
			if (x>=0 &&x%c==0 && (i+j+(x/c))>ma) ma=(i+j+(x/c));
			
		}
	cout<<ma;



	return 0;
}