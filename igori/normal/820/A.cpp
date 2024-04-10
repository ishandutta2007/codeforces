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
int min1,max1,a,l,n;


int main()
{
    cin>>n>>min1>>max1>>a>>l;
    int now=1,days=0;
    while(now<=n)
    {
        
        now=now+min(min1+days*a, max1);
      //  cout<<min(min1+days*a, max1)<<endl;
        days++;
        
        if(now>n)
          break;
        now-=l;
        if(now<1)
          now=1;
        
    }
    cout<<days;
    
    
    
}