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
int y,k,n,l=0;
int main()
{
	cin>>y>>k>>n;
	for(int i=1; i*k-y%k+y<=n; i++)
	 {
	 cout<<i*k-y%k<<' ';
	 l++;
	 }
	 if(!l)
	  cout<<"-1";
	return 0;
}