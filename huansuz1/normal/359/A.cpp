#include <iostream>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <vector>
#define ll long long

using namespace std;


ll n,m,a[543][166],l[543214][12];

int main()
{
//  freopen("sandwiches.in","r",stdin);
//  freopen("sandwiches.out","w",stdout);
    cin>>n>>m;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin>>a[i][j];

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (a[i][j] && ((i==0&&j==0)|| (i==0 && j==m-1)|| (i==n-1 && j==m-1)|| (i==n-1 && j==0))) {cout<<1; return 0;}
    
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) {
            if (a[i][j]==1 && (i==n-1 || i==0 || j==m-1 || j==0)) { cout<<2; return 0;}
            
        }
    
    cout<<4;
            
        
    

    


    


        
    return 0;
}