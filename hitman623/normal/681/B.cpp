#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,i,j;
    cin>>n;
    for(i=0;i<=n;i+=1234567)
    {
        for(j=0;j<=n-i;j+=123456)
        if((n-i-j)%1234==0) {cout<<"YES";exit(0);}
    }
    cout<<"NO";
    return 0;
}