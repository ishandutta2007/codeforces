#include <iostream>

using namespace std;

int main()
{
    int n,m,i,j,f=1;
    char a[100][100];
    cin>>n>>m;
    for(i=0;i<n;++i)
        for(j=0;j<m;++j)
         {cin>>a[i][j];
        if(a[i][j]=='C' ||a[i][j]=='M' || a[i][j]=='Y') {f=0;break;}
         }
         if(f==1) cout<<"#Black&White";
         else cout<<"#Color";
    return 0;
}