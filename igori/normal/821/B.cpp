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
int m,b;


int main()
{
    cin>>m>>b;
    long long max1=0;
    long long x=0,y=0;
    
    while(y>=0)
    {
        if((x/m)*m==x)
        y=b-x/m;
        else
        y=b-x/m-1;
        max1=max(max1,(x+y)*(x+1)*(y+1)/2);
        x++;
    }
    cout<<max1;
    
    
}