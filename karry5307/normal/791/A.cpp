#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
ll a,b,days;
int main()
{
    cin>>a>>b;
    while(a<=b)
    {
        a*=3,b*=2;
        days++;
    }
    cout<<days;
}