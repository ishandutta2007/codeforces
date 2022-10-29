
#include <iostream>

using namespace std;

int main()
{
     int n,i,f=1,l,w=0,m=0,g=1;
     char a[256];
     cin>>n>>a;
     for(i=0;i<n;++i)
     {  l=0;
      if(isalpha(a[i]) && f==1)
           {
               for(;isalpha(a[i]);++i)
            ++l;
                  if(l>m) m=l;
           i--;}
    else if(isalpha(a[i]) && g==1)
    {
       w++;g=0;
    }
    else if(a[i]=='_')
    {
        g=1;
    }
    else if(a[i]=='(')
    {
        f=0;
    }
    else if(a[i]==')')
    {
        f=1;
g=1;
    }
}
cout<<m<<"  "<<w;
    return 0;
}