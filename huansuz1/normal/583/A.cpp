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

long long n,z,a[1234567],b[123456],x[123456],y[1234567],ans;

int main() {
    cin>>n;          
    for (int i=0; i<n*n; i++){
        cin>>a[i]>>b[i];      
        if (x[a[i]]==0 && y[b[i]]==0){ x[a[i]]=1; y[b[i]]=1; cout<<i+1<<" ";}   
    }
    
    return 0;
}