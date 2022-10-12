#include <iostream>
#include <string>
using namespace std;

int main()
{
     int n;
     string g;
     cin>>g;
     n=g.size();
     for(int i=0; i<n-6; i++)
     {
         if((g[i]==g[i+1])&&(g[i]==g[i+2])&&(g[i]==g[i+3])&&(g[i]==g[i+4])&&(g[i]==g[i+5])&&(g[i]==g[i+6]))
           {
               cout<<"YES"; return 0;
           }
     }
     cout<<"NO";
}