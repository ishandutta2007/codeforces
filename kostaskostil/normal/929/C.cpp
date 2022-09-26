#include <bits/stdc++.h>

using namespace std;

set <int> f;
set <int> g;
set <int> h;

int cou(int l, int r, int i)
{
    set <int>::iterator it1,it2;
    if (i==1)
    {
    it1=f.lower_bound(l);
    it2=f.upper_bound(r);
    }
    if (i==2)
    {
    it1=g.lower_bound(l);
    it2=g.upper_bound(r);
    }
    if (i==3)
    {
    it1=h.lower_bound(l);
    it2=h.upper_bound(r);
    }
    int j=0;
    while (it1!=it2)
    {
        j++;
        it1++;
    }
    return j;
}

int main()
{
    int nf,ng,nh;
    cin>>nf>>ng>>nh;
    int x;
    for (int i=1; i<=nf; i++)
    {
        cin>>x;
        f.insert(x);
    }
    for (int i=1; i<=ng; i++)
    {
        cin>>x;
        g.insert(x);
    }
    for (int i=1; i<=nh; i++)
    {
        cin>>x;
        h.insert(x);
    }

    long long ans=0;
    for (set <int>::iterator it=f.begin(); it!=f.end(); it++)
    {
        int k=*it;
        long long x1,x2,x3;
        x2=cou(k+1,2*k,2);
        x3=cou(k+1,2*k,3);
        ans+=(((x2*(x2-1))*(x3*(x3-1)*(x3-2)))/12);
    }
    for (set <int>::iterator it=g.begin(); it!=g.end(); it++)
    {
        int k=*it;
        long long x1,x2,x3;
        x1=cou(k+1,2*k,1);
        x2=cou(k+1,2*k,2);
        x3=cou(k+1,2*k,3);
        ans+=x1*x2*(x3*(x3-1)*(x3-2))/6;
    }
    for (set <int>::iterator it=h.begin(); it!=h.end(); it++)
    {
        int k=*it;
        long long x1,x2,x3;
        x1=cou(k+1,2*k,1);
        x2=cou(k+1,2*k,2);
        x3=cou(k+1,2*k,3);
        ans+=x1*x2*(x2-1)*x3*(x3-1)/4;

    }
    cout<<ans<<"\n";
    return 0;
}