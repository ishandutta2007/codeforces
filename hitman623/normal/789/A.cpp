#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int main()
{
    long long n,k,c=0,x,i;
    cin>>n>>k;
    for(i=0;i<n;++i)
    {
        cin>>x;
        c+=x/k+!!(x%k);
    }
    cout<<c/2+!!(c%2);
    return 0;
}