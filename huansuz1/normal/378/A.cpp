#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <cmath>      
#include <string>
using namespace std;
long long  n,m,a,b,x[10],y[10],z,w,q;

int main(){
cin>>a>>b;
for (int i = 1; i <= 6; i++ ) 
	if (abs(a-i)<abs(b-i)) z++; else 
	if (abs(a-i)>abs(b-i)) w++; else q++;

cout<<z<<" "<<q<<" "<<w;




return 0;
}