
#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int n,a[100],i,j,p=0,f=1;
    char b[101][101];
    cin>>n;
    for(i=0;i<n;++i)
        cin>>a[i];
    for(i=0;i<=n;++i)
       { gets(b[i]);}
    for(i=1;i<=n;++i)
    {  p=0;
       for(j=0;b[i][j]!=0;++j)
       {
        if(b[i][j]=='a' || b[i][j]=='e' || b[i][j]=='i' || b[i][j]=='o' || b[i][j]=='u' || b[i][j]=='y' )
            ++p;
       }
       if(p!=a[i-1]) {cout<<"NO";f=0;break;}
    }
    if(f==1) cout<<"YES";
    return 0;
}