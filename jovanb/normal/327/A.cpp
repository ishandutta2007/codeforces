#include <bits/stdc++.h>

using namespace std;
int br[2][105];
int main()
{
    int n,i,x,j;
    cin>>n;
    cin>>x;
    br[x][1]++;
    for(i=2;i<=n;i++){
        br[0][i]=br[0][i-1];
        br[1][i]=br[1][i-1];
        cin>>x;
        br[x][i]++;
    }
    int ukup=br[1][n];
    int z=0;
    for(i=1;i<=n;i++){
        for(j=i;j<=n;j++){
            z=max(z,br[0][j]-br[0][i-1]-br[1][j]+br[1][i]);
        }
    }
    if(z==0 && br[0][n]==0)z=-1;
    cout<<ukup+z;
    return 0;
}