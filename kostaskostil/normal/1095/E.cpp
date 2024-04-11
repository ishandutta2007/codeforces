#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;

int a[1005000];
string s;
    int n;

int answ(string s)
{
    memset(a, 0, sizeof(a));
    int l0=0;
    for (int i=1; i<=n; i++)
        if (s[i-1]=='(')
            a[i]=a[i-1]+1;
        else
            a[i]=a[i-1]-1;
    for (int i=1; i<=n; i++)
    {
        if (a[i]<=1)
            l0=i;
        if (a[i]<0)
            return 0;
    }
    if (a[n]==2)
    {
        int ans=0;
        for (int i=l0+1; i<=n; i++)
            if (s[i-1]=='(')
                ans++;
        return ans;
    }
    else
        cout<<"awd\n";
}

main()
{
    cin>>n;
    cin>>s;
    for (int i=1; i<=n; i++)
        if (s[i-1]=='(')
            a[i]=a[i-1]+1;
        else
            a[i]=a[i-1]-1;
    if (abs(a[n])!=2)
    {
        cout<<"0\n";
        return 0;
    }
    if (a[n]==2)
        cout<<answ(s);
    else
    {
        string s2;
        for (int i=n-1; i>=0; i--)
        if (s[i]=='(')
            s2+=")";
        else
            s2+="(";
        cout<<answ(s2);
    }
}