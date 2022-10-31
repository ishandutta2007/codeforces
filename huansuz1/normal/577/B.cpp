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

long long n, x, m,ok[1347] , o[1234],z;

int main() {
    cin>>n>>m;
    for (int i=0; i<n; i++) {
        cin>>x;              
        x%=m;
        if (x==0 || ok[m-x]==1)  {
            cout<<"YES";
            return 0;
        }
        for (int j=0; j<m; j++)
            if (ok[j]==1)
                o[(j+x)%m]=1;
        o[x]=1;
        for (int j=0; j<m; j++)
            if (o[j])
                ok[j]=o[j];

    }
    if (ok[0]==1) cout<<"YES"; else cout<<"NO";

    
}