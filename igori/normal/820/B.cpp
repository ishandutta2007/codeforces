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
#define I i++
using namespace std;
float n,a,d;

float check(int x, int y,int z)
{
    float u1=y;
    float sum1=(u1-2)*180;
    float x1=(sum1-(u1-2)*d)/2;
    float u2=z-y+1;
    float sum2=(u2-2)*180;
    float x2=(sum2-(u2-2)*d)/2;
    
    return d-x1-x2;
}

int main()
{
    cin>>n>>a;
    d=((n-2)*180)/n;
    int m=2;
    float razn=180;
  
    int a1,a2,a3,a4;
    while(m<=n-1)
    {
        int l=m+1,r=n;
        while(l<=r)
        {
             float t=check(1,m,(l+r)/2);
             if(t>=a)
               {
               if(t-a<razn)
             {razn=t-a; a1=1; a2=m; a3=(l+r)/2;}
                   l=(l+r)/2+1;
               }
             if(t<a)
               {
                  if(a-t<razn)
                  {razn=a-t; a1=1; a2=m; a3=(l+r)/2; }
                  r=(l+r)/2-1; 
               }
        }
        m++;
        
    }
    cout<<a1<<" "<<a2<<" "<<a3;
}