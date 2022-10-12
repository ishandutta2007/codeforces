

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

vector<int> v;
int a1[200000],a2[200000];

IgorI_sollution
{
    int n;
    cin>>n;
    int k;
    forn(n)
    {
        cin>>k; 
        v.pb(k);
    }
    int f0;
    int l0;
    int t=0;
    forn(n)
    {
         if(v[i]==0 && t==0)
         {
              f0=i;
              t=1;
              l0=i;
         }
          if(v[i]==0)
          {
               l0=i;
          }
         a1[i]=999999;
         a2[i]=999999;
    }
    k=0;
    for(int i=f0; i<n; i++)
    {
         if(v[i]==0)
           k=0;
          a1[i]=k;
          k++;
    }
    for(int i=l0; i>=0; i--)
    {
         if(v[i]==0)
           k=0;
           a2[i]=k;
           k++;
    }
    for(int i=0; i<n; i++)
    {
         cout<<min(a1[i],a2[i])<<" ";
    }

     
     
     
}