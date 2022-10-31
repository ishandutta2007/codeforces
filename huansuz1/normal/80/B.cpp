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

double h,m,x,y,z;
string s;

int main() {
	cin>>s;            
	h=((s[0]-'0')*10)+(s[1]-'0');
	m=((s[3]-'0')*10)+(s[4]-'0');
	if (h>12)  h-=12;
	if (h==0)  h=12;
	if (m==0)  m=60;
	if (h!=12) x=((h*360)/12);
	if (m!=60) {y=((m*30)/60); z=(m*360)/60;} 
	cout<<x+y<<" "<<z;



	return 0;
}