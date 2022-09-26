#include <bits/stdc++.h>
#define int long long
using namespace std;

int gcd(int a, int b)
{
    while ((a!=0) and (b!=0))
    {
        if (a>b)
            a%=b;
        else
            b%=a;
    }
    return max(a, b);
}

pair<int, int> a[1000100];
int n;
    int cnt=0;
void out()
{
    int q=0;
    for (int i=1; i<=n-cnt; i++)
    {

        if (a[i].second==2)
            if (q==0)
        {
            for (int j=1; j<=cnt; j++)
                cout<<1;
            q=1;
        }


        cout<<a[i].second;
    }
    if (q==0)
            for (int j=1; j<=cnt; j++)
                cout<<1;

    cout<<"\n";
    exit(0);
}

main()
{
    string s;
    cin>>s;
    n=s.size();
    char t;
    for (int i=1; i<=n; i++)
    {
        t=s[i-1];
        if (t=='0')
        a[i]={i, 0};
        if (t=='2')
        a[i]={i, 2};
        if (t=='1')
        a[i]={100100, 1}, cnt++;
    }
    sort(a+1, a+n+1);
    out();
    return 0;
}