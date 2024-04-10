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
int d[10];
int main()
{
    
int n,cn;
cin>>cn;
n=cn;
int i=0;
while(n>0)
{
    d[i]=n%10;
    n/=10;
    i++;
}
int mm=d[i-1]+1;
for(int j=0; j<i-1; j++)
mm*=10;
mm-=cn;
cout<<mm;
    
}