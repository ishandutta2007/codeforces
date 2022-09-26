#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

typedef long long ll;
#define int ll

using namespace std;

void TEST()
{
        int n = 20;
    int p = 10;
    int k = 4;

    vector<int> v(n, k);
    for (int i=0; i<100; i++)
    {
        for (int i:v)
            cout<<i<<" ";
        cout<<"\n";

        vector<int> nt(n, 0);
        for (int i=0; i<n; i++)
        {
            if (i==p)
                nt[(i+1)%n]+=v[i];
            else
            {
                nt[(i+1)%n]+=(v[i]+1)/2;
                nt[(i+n-1)%n]+=(v[i])/2;
            }
        }
        v=nt;
    }
}

int ask(int x)
{
    cout<<"? "<<x<<endl;
    int y;
    cin>>y;
    return y;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin>>n>>k;

    if (n < 500)
    {
        for (int i=0; i<500; i++)
            ask(1);

        vector<int> v(n);
        for (int i=0; i<n; i++)
            v[i]=ask(i+1);
        for (int i=0; i<n; i++)
            if (v[i]==k)
            if (v[(i+1)%n]>k)
            if (v[(i+n-1)%n]<k)
        {
            cout<<"! "<<i+1<<endl;
            return 0;
        }
    }

    for (int i=1; i<=320; i++)
        ask(1);

    int i;
    int res;
    for (i=1; i<=n; i+=320)
    {
        res=ask(i);
        if (res != k)
            break;
    }

    if (res < k)
    {
        while (true)
        {
            int j = i+320;
            while (j>n)
                j-=n;
            if (ask(j) < k)
                i=j;
            else
                break;
        }
        while (true)
        {
            i=i+1;
            if (i>n)
                i-=n;
            res=ask(i);
            if (res==k)
                break;
        }
        cout<<"! "<<i<<endl;
        return 0;
    }
    else
    {
        while (true)
        {
            int j = i-320;
            while (j<1)
                j+=n;
            if (ask(j) > k)
                i=j;
            else
                break;
        }
        while (true)
        {
            i=i-1;
            if (i<1) i+=n;
            res=ask(i);
            if (res==k)
                break;
        }
        cout<<"! "<<i<<endl;
        return 0;
    }
}