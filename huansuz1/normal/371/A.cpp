#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <map>
#include <set>

#define f first
#define s second
#define mp make_pair 
#define ll long long

using namespace std;

int a[1234][1234],q=0,n,m,x,z,ans,b[1234],c[1234];

int main(){
    cin>>n>>m;
    for (int i=0; i<n; i++){
        cin>>x;
        if (i==0) a[0][0]=x; else a[i/m][i%m]=x;
    }
    for (int i=0; i<n/m; i++)
        for (int j=0; j<m; j++)
            if (a[i][j]==1)  b[j]++; else c[j]++;
    for (int j=0; j<m; j++)
            ans+=min(b[j],c[j]);


    cout<<ans;

      

    return 0;
}