#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

#define then ;
#define cin(n); int n; cin>>n;
#define stop return 0;
//IgorI
//It is true or false
//Is it true or false?

int main()
{
     string a,b;
     cin>>a>>b;
     cin(n);
     for(int i=0; i<n; i++)
     {
          cout<<a<<" "<<b<<endl;
          string c,d;
          cin>>c>>d;
          if(a==c)
            a=d;
          if(b==c)
            b=d;
            
     }
     cout<<a<<" "<<b;
}