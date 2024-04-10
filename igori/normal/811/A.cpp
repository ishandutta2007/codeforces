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


int main()
{
    int n,m;
    cin>>n>>m;
    int i=1;
    while(n>=0 && m>=0)
    {
        if(i%2==1 && n<i)
        {
            cout<<"Vladik";
            return 0;
        }
        if(i%2==1 && n>=i)
          n-=i;
        if(i%2==0 && m<i)
        {
            cout<<"Valera";
            return 0;
        }
        if(i%2==0 && m>=i)
          m-=i;
        
        i++;
        
        
    }
}