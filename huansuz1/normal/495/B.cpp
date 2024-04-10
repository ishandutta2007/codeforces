//mukh1t dauirkhan
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>

int a,b,z;


using namespace std;
int main () {
cin>>a>>b;
if (a==b) {cout<<"infinity"; exit(0);}
a-=b;
for (int i=1;i*i<=a;i++){
if (a%i==0 && i>b) z++;
if (a/i>b && a/i!=i && a%i==0) z++;
	}
	cout<<z;
	return 0;
}