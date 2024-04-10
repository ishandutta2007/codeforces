#include <bits/stdc++.h>

using namespace std;
long long a,b,c,t;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c;
        long long s =a+b+c;
        if(a+c<=b){cout<<0<<endl;continue;}

        cout<<max((long long )0,min(((s-1)/2),s-a)-b+1)<<endl;


    }
    return 0;
}