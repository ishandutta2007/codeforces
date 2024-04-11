#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef int ll;


main()
{
    int n;
    cin>>n;
    int s=11;
    while (n >= 10)
    {
    s=0;
    while (n>0)
        s+=n%10, n/=10;
    n=s;
    }
    cout<<n;
}