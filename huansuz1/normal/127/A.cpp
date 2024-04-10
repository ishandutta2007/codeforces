#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

double x[1234] , y[1234] , s , p;
int n , k;

int main(){

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	for (int i=0; i<n-1; i++)
		s+=sqrt((x[i]-x[i+1])*(x[i]-x[i+1])+(y[i]-y[i+1])*(y[i]-y[i+1]));
	p = (s / 50)*k;
	printf("%.12lf",p);		
		




	return 0;
}