#include <iostream>

using namespace std;

int main()
{
    char a[101];int m=0,i=0,p=0,f=1;
    cin>>a;
    while(a[i]!=0)
    {
      if(a[i]=='A' || a[i]=='E' ||a[i]=='I' ||a[i]=='O' ||a[i]=='U' || a[i]=='Y')
      {
          if(i-p>m) m=i-p;
          if(p==0 && f==1) {m++;f=0;}
          p=i;
      }
      i++;
    }
    if(p==0) { if(a[0]=='A' || a[0]=='E' ||a[0]=='I' ||a[0]=='O' ||a[0]=='U' || a[0]=='Y') m=i;
               else m=i+1;}
    else if(i-p>m)m=i-p;
    cout<<m;
    return 0;
}