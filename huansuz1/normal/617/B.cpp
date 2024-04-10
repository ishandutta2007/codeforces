#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>
#define ll long long
using namespace std;


long long n,s=1,q,z,p;

int main() {
    cin>>n;
    for (int i=0; i<n; i++) {
    	cin>>q;              
    	if (z!=0 && q==1) s*=(i-p);
    	if (q==1) { z++; p=i;}
    }
    if (z==0) cout<<0; else cout<<s;

    return 0;             
}