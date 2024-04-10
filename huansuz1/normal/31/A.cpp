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

int a[1234],n,x,y,z,p;
int main() {

    cin>>n;
    for (int i=0; i< n; i++)
    	cin>>a[i];
    for (int i=0; i<n; i++)
    	for (int j=0; j<n; j++)
    		for (int o=0; o<n; o++)
    			if (i!=j && o!=j && a[i]==a[o]+a[j]) {p=1; x=i+1; y=j+1; z=o+1; cout<<x<<" "<<y<<" "<<z; exit(0);}

    cout<<-1;
return 0;
}