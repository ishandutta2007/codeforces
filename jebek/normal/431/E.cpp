#include <iostream>
#include<algorithm>
#include<map>

using namespace std;

const long double inf=1000000000;
map<int,int>t;
map<int,long long>m;
int n,q,a[100010];
long double p;

void del(int x)
{
    int y=x;
    while(x<=1000000000)
    {
        m[x]-=x-y;
        t[x]--;
        x+=x&(-x);
    }
}

void add(int x)
{
    int y=x;
    while(x<=1000000000)
    {
        m[x]+=x-y;
        t[x]++;
        x+=x&(-x);
    }
}

bool fin2(long double y,long double x)
{
    long double f=n;
    if(p+f*(y-inf)>=x)
        return true;
    return false;
}

bool fin(long double y,long double x)
{
    if(y>=1000000000)
        return fin2(y,x);
    long double f=y;
    long long k=f;
    long double f1=t[0];
    long double ans=f1*y;
    while(k>0)
    {
        if(t[k]>0)
        {
            ans+=m[k];
            f=t[k];
            f1=k;
            ans+=f*(y-f1);
        }
        k-=k&(-k);
    }
   // cout<<y<<" "<<x<<" "<<ans<<endl;
    if(ans>=x)
        return true;
    return false;
}

long double bs(long long x)
{
    long double l=0,r=10000000000000000;
    for(int i=1;i<=100;i++)
    {
        long double mid=(l+r)/2;
        if(fin(mid,x))
            r=mid;
        else
            l=mid;
    }
    return l;
}

int main()
{
    cin>>n>>q;
    long double f=n;
    p=1000000000*f;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]!=0)
            add(a[i]);
        else
            t[0]++;
        p-=a[i];
    }
    for(int i=0;i<q;i++)
    {
      //  cout<<"*";
        int qw;
        cin>>qw;
        if(qw==1)
        {
            int x,y;
            cin>>x>>y;
            p+=a[x-1];
            p-=y;
            if(a[x-1]!=0)
                del(a[x-1]);
            else
                t[0]=t[0]-1;
            a[x-1]=y;
            if(y!=0)
                add(y);
            else
                t[0]++;
        }
        else
        {
            long long x;
            cin>>x;
            cout<<bs(x)<<endl;
        }
    }
}