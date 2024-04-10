#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#define f first
#define s second
#define mp make_pair                                                        
#define ll long long

using namespace std;

int n,a[12345] ,b[12345],c[12345],z,zz;

int main(){
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>a[i];           
        c[i]=a[i];  
    }
    sort(a,a+n);
    b[a[n-1]]=1;
    z=1;
    for (int i=n-2; i>=0; i--){
        if (a[i]!=a[i+1]) {z++; b[a[i]]=z;} else z++;
    }
    for (int i=0; i<n; i++)
        cout<<b[c[i]]<<" ";

    return 0;
}