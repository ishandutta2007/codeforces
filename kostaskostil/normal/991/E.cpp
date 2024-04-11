#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;

int a[100];
int b[100];

int sum=0;

int cnk(int n, int k)
{
    int res=1;
    for (int i=n-k+1; i<=n; i++)
        res*=i, res/=(i-(n-k));
    return res;
}

int permut(int i)
{
    if (i==10)
    {
        int n=0;
        for (int j=0; j<10; j++)
            n+=a[j];
        int r=cnk(n-1, a[0]);
        n-=a[0];
        for (int j=1; j<10; j++)
        {
            r*=cnk(n, a[j]);
            n-=a[j];
        }
       // cout<<r<<"\n";
        sum+=r;
    }
    else
    {
    if (b[i]==0)
        permut(i+1);
    else
    {
        for (a[i]=1; a[i]<=b[i]; a[i]++)
            permut(i+1);
    }
    }
}

main()
{
    string s;
    cin>>s;
    for (int i=0; i<s.size(); i++)
        b[ (s[i]-'0') ]++;
    permut(0);
    cout<<sum<<"\n";
    return 0;
}