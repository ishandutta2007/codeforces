#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int n,k,i,t=0,e=0,q,w;
    char a[100][101],pass[101];
    cin>>n>>k;
    for(i=0;i<n;++i)
        cin>>a[i];
    cin>>pass;
    for(i=0;i<n;++i)
    {
      if(strlen(a[i])<strlen(pass)) ++t;
      if(strlen(a[i])<=strlen(pass)) ++e;
    }
    q=(t/k)*5+t+1;
    w=((e-1)/k)*5+e;
    cout<<q<<" "<<w;
    return 0;
}