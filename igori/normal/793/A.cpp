#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

#define NO "NO"
#define YES "YES"
#define forn(n) for(int i=0; i<(n); i++)
#define pb push_back
#define sz size()
#define IgorI_sollution int main()

using namespace std;

string s;


IgorI_sollution
{
     int n,k;
     int m[120000];
     cin>>n>>k;
     int cb=0;
     long long min=1000000000000;
     for(int i=0; i<n; i++)
       { cin>>m[i]; 
       if(i==0) 
       cb=m[i]%k;
       else
       {
            if(m[i]%k!=cb)
            {
                 cout<<-1; return 0;
            }
       }
       if(m[i]<min)
          min=m[i];
       }
       long long ans=0;
       for(int i=0; i<n; i++)
       {
            ans+=(m[i]-min)/k;
       }
       cout<<ans;
     
     
     
     
     
     
}