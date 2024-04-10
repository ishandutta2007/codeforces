// Hydro submission #62972c4bb0c5e75beb1586d5@1654074443932
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,i;
    long long s;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>s;
        printf("%lld\n",s/n/n);
    }
    return 0;
}