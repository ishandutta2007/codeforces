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


map<char,int> mp;
int n,p,ma,z;
int a[12345];

int main(){
    cin>>n;
    for (int i=0; i<n; i++)  {
    	cin>>p;
    	a[p]=1;
    }
    for (int i=1; i<=n; i++)
    	if (a[i]!=1) z++;
    cout<<z;

	return 0;
}