#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

double n,x,y,p;

int main(){
	cin>>n>>x>>y;
	double m=(n*y)/100;
	double t=m;
	if ((int)m!=t)  p=(int)m+1; else p=(int)m;
	if (x<p) cout<<p-x; else cout<<0;
	
	return 0;

}