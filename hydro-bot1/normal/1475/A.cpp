// Hydro submission #6274cd11997df5291339d1b3@1651821841852
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i;
    long long n;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        while(n%2==0)
        n/=2;
        printf(n-1?"YES\n":"NO\n");
    }
    return 0;
}