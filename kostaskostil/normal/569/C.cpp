#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;

const int N=1200500;
int p[N];

bool pal(int n)
{
    int n0=n;
    vector<int> t;
    while (n>0)
    {
        t.push_back(n%10);
        n/=10;
    }
    for (int i:t)
    {
        n*=10;
        n+=i;
    }
    //cout<<n<<"\n";
//    if (n==n0)
//        cout<<n<<"\n";
    return (n==n0);
}

main()
{
    p[1]=1;
    for (int i=2; i<N; i++)
        if (p[i]==0)
            for (int j=2*i; j<N; j+=i)
                p[j]=1;
    int p0, q0;
    cin>>p0>>q0;
    int c0, c1;
    c0=0;
    c1=0;
    int n=0;
    while (n<N-1)
    {
        n++;
        if (pal(n))
            c1++;
        if (p[n]==0)
            c0++;// cout<<n<<"\n";
    }
    while (q0*c0>p0*c1)
    {
        if (pal(n))
            c1--;
        if (p[n]==0)
            c0--;// cout<<n<<"\n";
        n--;
    }
    cout<<n<<"\n";
    return 0;
}