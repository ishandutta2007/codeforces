#include <iostream>

using namespace std;
int main()
{
    long x,y,i,a,b,c,p=0;
    cin>>x>>y;
    a=y;b=y;c=y;
    while(a!=x || b!=x || c!=x)
    {
       if(a!=x)
      { a=b+c-1;
       ++p;}
       if(a>x) a=x;
       if(b!=x)
      { b=a+c-1;
       ++p;}
       if(b>x) b=x;
        if(c!=x)
       {  c=a+b-1;
       ++p;}
       if(c>x) c=x;
    }
    cout<<p;
    return 0;
}