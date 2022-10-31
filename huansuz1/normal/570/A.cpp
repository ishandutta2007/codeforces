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

long long ans,a[1234],n,m,x,s,b[1234];

int main() {
    cin>>n>>m;
    for (int i=0; i<m; i++) {
        ans=0; s=0;
        for (int j=0; j<n; j++) {
            cin>>x;
            if (x>s) {s=x; ans=j;}  
        }
        b[ans]++;
    }

    ans=0; s=0;

    for (int i=0; i<n; i++) {
        if (b[i]>s) {s=b[i]; ans=i;}
    }
    
    cout<<ans+1;
    

    return 0;
}