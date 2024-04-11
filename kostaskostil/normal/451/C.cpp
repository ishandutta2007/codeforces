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
    int ttt;
    cin>>ttt;
    for (int qqq=0; qqq<ttt; qqq++)
    {
        cin>>n>>k>>d1>>d2;
        if (n%3!=0)
        {
            cout<<"no\n";
            continue;
        }
        int d=max(d1, d2);
        if (check(d-d1, d, d-d2) or check(d1, 0, d2) or check(0, d1, d1+d2) or check(d1+d2, d2, 0))
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
}