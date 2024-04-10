#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <string>

using namespace std;
int a[4],z=1;
int main(){
	cin>>a[0]>>a[1]>>a[2]>>a[3];
	sort(a,a+4);
	for (int i=1; i<4; i++)
	if (a[i]!=a[i-1]) z++;
     cout<<4-z;;
}