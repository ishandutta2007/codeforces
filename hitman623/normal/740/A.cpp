#include <iostream>

using namespace std;

int main()
{
   long long n,a,b,c;
   cin>>n>>a>>b>>c;
   n%=4;
   n=4-n;
   switch(n)
   {
      case 1:if(a<b+c && a<3*c) cout<<a;
             else if(a>b+c && a<3*c) cout<<b+c;
             else if(a<b+c && a>3*c) cout<<3*c;
             else if(b+c>3*c) cout<<3*c;
             else cout<<b+c;
             break;
      case 2:if(b<2*a && b<2*c) cout<<b;
             else if(b<2*a && b>2*c)cout<<2*c;
             else if(b>2*a && b<2*c) cout<<2*a;
             else if(2*a>2*c) cout<<2*c;
             else cout<<2*a;
             break;
      case 3:if(c<3*a && c<a+b)
                cout<<c;
                else if(c>3*a && c<a+b) cout<<3*a;
                else if(c<3*a && c>a+b) cout<<a+b;
                else if(3*a>a+b) cout<<a+b;
                else cout<<3*a;
                break;
       case 4: cout<<0;
       break;
   }
    return 0;
}