#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    cout<<max(0,c*(c+1)/2*a-b);
    return 0;
}