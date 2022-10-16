#include <iostream>

using namespace std;
int n, a1, a2, a3, b, c, d;
int main()
{
cin>>n;

    cin>>a1>>b;
     n-=a1;
     b-=a1;
     cin>>a2>>c;
     n-=a2;
     c-=a2;
     cin>>a3>>d;
     n-=a3;
     d-=a3;
     while(n!=0 && b!=0)
     {
        a1++;
        b--;
        n--;
     }
     while(n!=0 && c!=0)
     {
        a2++;
        c--;
        n--;
     }
     while(n!=0 && d!=0)
     {
        a3++;
        d--;
        n--;
     }
    cout<<a1<<' '<<a2<<' '<<a3;
    return 0;
}