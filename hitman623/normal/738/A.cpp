#include <iostream>

using namespace std;

int main()
{
    int n,i,f=0,l=0;
    char a[101],b[101];
    cin>>n;
    cin>>a;
    for(i=0;i<n;++i)
    {
      if(a[i]=='o' && a[i+1]=='g' && a[i+2]=='o')
      {if(f==0){b[l++]='*';b[l++]='*';b[l++]='*';}f=1;}
      else if(a[i]=='g' && f==1) ;
      else if(a[i]=='o' && f==1) f=0;
      else {b[l++]=a[i];f=0;}
    }
    b[l]='\0';
    cout<<b;
    return 0;
}