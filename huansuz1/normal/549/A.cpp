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

char a[123][123];
int n,m,x,y,z,q,ans;

int main(){
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cin>>a[i][j];

    for (int i=2; i<=n; i++)
        for (int j=2; j<=m; j++)  {
            x=0,y=0,z=0,q=0;
            if (a[i][j]=='f') x=1;     
            if (a[i-1][j]=='f') x=1;     
            if (a[i-1][j-1]=='f') x=1;   
            if (a[i][j-1]=='f') x=1;     
            
            if (a[i][j]=='a') y=1;     
            if (a[i-1][j]=='a') y=1;     
            if (a[i-1][j-1]=='a') y=1;   
            if (a[i][j-1]=='a') y=1;

            if (a[i][j]=='c') z=1;     
            if (a[i-1][j]=='c') z=1;     
            if (a[i-1][j-1]=='c') z=1;   
            if (a[i][j-1]=='c') z=1;

            if (a[i][j]=='e') q=1;     
            if (a[i-1][j]=='e') q=1;     
            if (a[i-1][j-1]=='e') q=1;   
            if (a[i][j-1]=='e') q=1;

            if (x+y+z+q==4) ans++; 

        }
        cout<<ans;
        return 0;


}