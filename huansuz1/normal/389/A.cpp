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

int z,a[123],n,sum;

int main(){
    cin>>n;
    for (int i=0; i<n; i++)
        cin>>a[i];
        sort(a,a+n);
    while(a[0]!=a[n-1]){
        for (int j=n-1; j>=1; j--)
            if (a[j]!=a[j-1]) a[j]-=a[j-1];
        sort(a,a+n);
    }
    
    
    for (int i=0; i<n; i++) {
        sum+=a[i];
    }
    cout<<sum;

    return 0;
}