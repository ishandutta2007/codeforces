#include <bits/stdc++.h>

#define int long long
#define fi first
#define se second
#define pb push_back

using namespace std;

int q(string s)
{
    int a=0;
    for (int i=0; i<s.size(); i++)
        a*=10, a+=signed(s[i]-'0');
    return a;
}

int ppow(int a, int b)
{
    if (b==0)
        return 1;
    return a*ppow(a, b-1);
}

int f(string s)
{
    int k=q(s);
    int l=s.size();
    if (l==1)
    {
        if (k==9)
            return 1989;
        return 1990+k;
    }

    int g=f(s.substr(1, s.size()-1));
    int p10=ppow(10, l);
    for (int i=k; ;i+=p10)
        if (i>g)
            return i;
}

main()
{
    int n;
    cin>>n;
    string s;
    for (int i=1; i<=n; i++)
    {
        cin>>s;
        string g;
        for (int i=4; i<s.size(); i++)
            g+=s[i];
        cout<<f(g)<<"\n";
    }

    return 0;
}