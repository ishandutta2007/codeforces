// Hydro submission #6274d718997df5291339e561@1651824408970
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
        if(n<6) n=6;
        else if(n>6&&n%2) n++;
        printf("%lld\n",n/2*5);
    }
    return 0;
}