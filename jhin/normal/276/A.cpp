#include <bits/stdc++.h>
#include <math.h>
#include <map>
#include<string>
using namespace std;
int n,k,f,t,sum=-1e9,a[102],a2[102];
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {cin>>f>>t;
    if(t>k)sum=max(sum,f-t+k);
    else sum=max(sum,f);}
    cout<<sum;

    return 0;
}