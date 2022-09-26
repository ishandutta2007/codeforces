#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#define int long long
#define fi first
#define se second

using namespace std;

int a[100500];
    int n, k, d1, d2;
bool check(int a, int b, int c)
{
    if (k>=a+b+c)
        if ((k-a-b-c)%3==0)
            if (n-k>=3*max(max(a, b), c)-a-b-c)
                if ((n-k-(3*max(max(a, b), c)-a-b-c))%3==0)
                    return true;
    return false;
}

main()
{
int n, s;
cin>>n>>s;
cout<<(s+n-1)/n;
}