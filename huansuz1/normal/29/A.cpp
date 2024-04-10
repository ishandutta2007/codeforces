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

int a[1234],b[1234],n;
int main() {

    cin>>n;
    for (int i=0; i< n; i++)
    	cin>>a[i]>>b[i];
    for (int i=0; i<n; i++)
    	for (int j=0; j<n; j++)
    		if (a[j]+b[j]==a[i] && a[i]+b[i]==a[j]) {cout<<"YES"; exit(0);}
    cout<<"NO";
return 0;
}