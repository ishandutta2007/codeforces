#include <bits/stdc++.h>

using namespace std;

int main()
{
    long n,k,i;
    cin>>n>>k;
    if(k>n) cout<<k;
    else
    {
        cout<<(n/k)*k+k;
    }
    return 0;
}