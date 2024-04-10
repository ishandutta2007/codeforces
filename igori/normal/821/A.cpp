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
int n;
int a[50][50];
int t;


int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(a[i][j]==1)
            continue;
            t=0;
            int k=a[i][j];
            for(int s=0; s<n; s++)
            {
                int a1=a[i][s];
                for(int t2=0; t2<n; t2++)
                {
                    if(a[t2][j]==k-a1)
                    {
                        t=1;
                        break;
                    }
                }
            }
            if(t==0)
            {cout<<"No";return 0;}
        }
    }
    cout<<"Yes";
    
    
}