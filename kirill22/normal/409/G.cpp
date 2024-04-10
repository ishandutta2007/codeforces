#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

double ans, x, y;
int n, i;

int main()
{
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>x>>y;
        ans=ans+y;
    }
    cout.precision(2);
    cout<<fixed<<(5+0.+ans/n);
}