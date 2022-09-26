#include <bits/stdc++.h>
#define int long long
using namespace std;

long long gcd(long long a, long long b)
{
    while ((a>0) and (b>0))
    {
        if (a>b)
            a%=b;
        else
            b%=a;
    }
    return max(a,b);
}

map<int, int> dv;

int sqrt(int n)
{
    int l=0;
    int r=2e9;
    while (r>l+1)
    {
        int m=(r+l)/2;
        int q=m*m;
        if (q==n)
            return m;
        if (q<n)
            l=m;
        else
            r=m;
    }
    return -1;
}

int sqr3(int n)
{
    int l=0;
    int r=2000000;
    while (r>l+1)
    {
        int m=(r+l)/2;
        int q=m*m*m;
        if (q==n)
            return m;
        if (q<n)
            l=m;
        else
            r=m;
    }
    return -1;
}


int sqrf(int n)
{
    int l=0;
    int r=40000;
    while (r>l+1)
    {
        int m=(r+l)/2;
        int q=m*m*m*m;
        if (q==n)
            return m;
        if (q<n)
            l=m;
        else
            r=m;
    }
    return -1;
}

vector <int> last;
    int n;
int del[100100];


int upd(int q)
{
    for (int k=0; k<n; k++)
        if (del[k]!=0)
            if (last[k]%q==0)
            {
                dv[q]+=del[k];
                dv[last[k]/q]+=del[k];
                del[k]=0;
                upd(last[k]/q);
            }
}

main()
{
    for (int i=0; i<100100; i++)
        del[i]=1;
    cin>>n;
    int x;
    for (int i=1; i<=n; i++)
    {
        cin>>x;
        int s2=sqrt(x);
        int s3=sqr3(x);
        int s4=sqrf(x);
        if (s4!=-1)
        {
            dv[s4]+=4;
        }
        else
        if (s3!=-1)
        {
            dv[s3]+=3;
        }
        else
        if (s2!=-1)
        {
            dv[s2]+=2;
        }
        else
            last.push_back(x);
    }
    n=last.size();
    for (pair<int, int> pa: dv)
    {
        upd(pa.first);
    }

    for (int i=0; i<n; i++)
    if (del[i]!=0)
    for (int j=0; j<n; j++)
    if (del[j]!=0)
    if (gcd(last[i], last[j])!=1)
    {
        int q=gcd(last[i], last[j]);
        if (q==last[i])
        {
            del[j]=0;
            del[i]++;
        }
        else
        {
            upd(q);
        }
    }
    int ans=1;
    for (pair<int, int> pa: dv)
    {
        ans*=(pa.second+1);
        ans%=998244353;
    }
    for (int i=0; i<n; i++)
        if (del[i]!=0)
    {
        ans*=((del[i]+1)*(del[i]+1));
        ans%=998244353;
    }
    cout<<ans<<"\n";
    return 0;
}