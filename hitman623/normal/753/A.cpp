#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,s=0,i;
    cin>>n;
    cout<<((int)sqrt(1+8*n)-1)/2<<endl;
    for(i=1;i<=n;++i)
    {   s+=i;
        if(s+i+1>n) {cout<<i+n-s<<" ";break;}
        else cout<<i<<" ";
    }
    return 0;
}