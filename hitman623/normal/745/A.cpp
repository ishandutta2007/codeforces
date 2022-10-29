#include <bits/stdc++.h>

using namespace std;

int main()
{
    char a[55],b[55],t;
    cin>>a;
    int i,j,c=1;
    strcpy(b,a);
    int m=strlen(a);
    for(i=0;i<m;++i)
        { t=a[m-1];
          for(j=m-1;j>0;--j)
          {
              a[j]=a[j-1];
          }
          a[j]=t;
          if(strcmp(b,a)!=0) c++;
          else break;
        }
        cout<<c;
    return 0;
}