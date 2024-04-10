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

int n,a[22345],x[3456],y[3456],z;
long long s1,s2;
string s="first";

int main() {
    cin>>n;
 	for(int i=0; i<n; i++)
 		cin>>a[i];
 	for (int i = 0; i < n; i++)
    {
        int j = i;
        for (int t = i; t < n; t++)
            if (a[j] > a[t]) 
                j = t;
        if (i != j) {x[z]=i; y[z]=j; z++;}
        swap(a[i], a[j]);
    }
    cout<<z<<endl;
    for (int i=0; i<z; i++)
    	cout<<x[i]<<" "<<y[i]<<endl;

	return 0;
}