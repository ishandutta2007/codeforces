#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <sstream>

#define NO "NO"
#define YES "YES"
#define forn(n) for(int i=0; i<(n); i++)
#define pb push_back
#define sz size()
#define IgorI_sollution int main()
#define I i++

using namespace std;



IgorI_sollution
{
    string s;
    cin>>s;
    long long ans=0;
    long long countb=0;
    
    int n=s.sz;
    int lb=0;
    for(int i=n-1; i>=0; i--)
    {
         if(s[i]=='b')
         {
               
                 countb++;
              
         }
         if(s[i]=='a')
         {
              
                   ans+=countb;
                   ans=ans%1000000007;
                   countb*=2;
                   countb=countb%1000000007;
              
         }
    }
    cout<<ans;
     
   
    
    
    
}