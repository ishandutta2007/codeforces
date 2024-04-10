#include <iostream>
#include <string>

using namespace std;

int main()
{
     int n;
     int f[200002];
     cin>>n;
     for(int i=0; i<n; i++)
     {
         cin>>f[i];
     }
     f[n]=0;
     f[n+1]=0;
     if (n<2)
     {
         if( f[0]%2==0)
            cout<<"YES";
         else
            cout<<"NO";
         return 0;
     }
     int now=f[0];
     int next=f[1];
     for(int i=0; i<n; i++)
     {
         if(now%2==1)
            {
                 next--;
                 if(next<0)
                 {
                    cout<<"NO";return 0;
                 }
            }
         now=next;
         next=f[i+2];


     }
     cout<<"YES";
}