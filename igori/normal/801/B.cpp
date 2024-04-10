#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    string x,y="",z;
    cin>>x>>z;
    int n=x.size();
    for(int i=0; i<n; i++)
    {
        if(x[i]<z[i])
        {
            cout<<-1; return 0;
        }
        if(x[i]==z[i])
        {
            y=y+'z';
        }
        if(x[i]>z[i])
        {
            y=y+z[i];
        }
    }
    cout<<y;

}