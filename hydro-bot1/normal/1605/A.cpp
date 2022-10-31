// Hydro submission #6297298a1008115bd64b4f0f@1654073739584
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,a,b,c,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>a>>b>>c;
        printf("%d\n",abs(a+c-b*2)%3?1:0);
    }
    return 0;
}