#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>
using namespace std;

int n,m;
long long ans,x,q;


int main(){
    cin>>n>>m;
    for (int i=0; i<n; i++) {
        long long q=1000000009;
        for (int j=0; j<m; j++) {
            cin>>x;
            q=min(q,x);
        } 
        ans=max(ans,q);
    }
    cout<<ans;
    return 0;
}