#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <vector>

using namespace std;


int n,m;

int main(){
	cin>>n>>m;
if (n==m) {
	cout<<(n+m)/3;
	exit(0);
}
if (n-m==1 || m-n==1) {
	cout<<(n+m)/3;
	exit(0);
}
if (n>=m+m)  {
	cout<<m;
	exit(0);
}
if (n+n<=m)  {
	cout<<n;
	exit(0);
}
cout<<(n+m)/3;



}