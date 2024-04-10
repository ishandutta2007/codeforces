#include <bits/stdc++.h>
#include <math.h>
#include <map>
using namespace std;
double n,x,sum;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){cin>>x;sum+=x;}
    cout<<setprecision(10)<<sum/n;

    return 0;
}