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

int n;

int k;

IgorI_sollution
{
     int a,b,c;
     cin>>a>>b>>c;
     cin>>n;
     int ans=0;
     for(int i=0; i<n; i++)
     {
          cin>>k;
          if(k>b && k<c)
          ans++;
     }
     cout<<ans;
     
     
}