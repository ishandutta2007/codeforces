#include <bits/stdc++.h>

using namespace std;

int main()
{
    long n,c=1,i,d=0,f=0;
    char a[200005],h='0',v='0';
    cin>>n>>a;
    for(i=0;i<n;++i)
    {
      if(a[i]=='R' || a[i]=='L')
      {   if(h=='0') h=a[i];
          else if(h!=a[i])
          {c++;h='0';v='0';i--;continue;}
      }
        if(a[i]=='U' || a[i]=='D')
      {   if(v=='0') v=a[i];
          else if(v!=a[i])
          {c++;v='0';h='0';i--;}
      }
    }
    cout<<c;
    return 0;
}