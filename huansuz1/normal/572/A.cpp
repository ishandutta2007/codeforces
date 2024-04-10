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

long long n, x,y, m,a[134734] , b[123434],z;

int main() {
    cin>>n>>m;
    cin>>x>>y;
    for (int i=0; i<n; i++)
        cin>>a[i];
    for (int i=0; i<m; i++)
        cin>>b[i];
    if (a[x-1]<b[m-y]) cout<<"YES"; else cout<<"NO" ;

    
}