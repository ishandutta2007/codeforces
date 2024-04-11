#include <bits/stdc++.h>

using namespace std;

vector<set<int>> key;
int lok[100100];
int n;
int lef[100100];
int righ[100100];
int anslef[100100];
int ansrigh[100100];


long long f(long long a, long long b, int i)
{
    if ((a==-1) or (b==-1))
        return -1;
    if (i==0)
        return max(a,b);
    else
        return min(a,b);
}

int main()
{
    int a,b;
    cin>>n>>a>>b;
    //n=100000; a=n/2; b=n;

    key.resize(n+5);

    //for (int i=1; i<n; i++)
    //lok[i]=i;


    //for (int i=1; i<n; i++)
    //key[n-i].insert(i);
    //key[1].insert(n);

    int x;
     for (int i=1; i<n; i++)
    {
        cin>>lok[i];
    }
    for (int i=1; i<=n; i++)
    {
        cin>>x;
        key[x].insert(i);
    }

    lef[1]=-1;
    for (int i=2; i<=n; i++)
    {
        lef[i]=-2;
        if (key[lok[i-1]].empty())
            lef[i]=-1;
        set<int>::iterator it=(key[lok[i-1]].lower_bound(i));
        if (it==key[lok[i-1]].begin())
            lef[i]=-1;
        if (lef[i]==-2)
            lef[i]=*(--it);
    }


    righ[n]=-1;
    for (int i=1; i<n; i++)
    {
        righ[i]=-2;
        if (key[lok[i]].empty())
            righ[i]=-1;
        set<int>::iterator it=(key[lok[i]].upper_bound(i));
        if (it==key[lok[i-1]].end())
            righ[i]=-1;
        if (righ[i]==-2)
            righ[i]=*it;
    }


    anslef[a+1]=lef[a+1];
    for (int i=a+2; i<=n; i++)
        anslef[i]=f(anslef[i-1],lef[i],1);

    ansrigh[a-1]=righ[a-1];
    for (int i=a-2; i>0; i--)
        ansrigh[i]=f(ansrigh[i+1],righ[i],0);

    long long answ=0;
    int endof=0;

    int used[100100];
    for (int i=0; i<=100000; i++)
        used[i]=0;
    while (endof==0)
    {
        if (used[b]==1)
           {
            cout<<"-1\n";
            exit(0);
        }

       //cout<<a<<" "<<b<<" "<<k<<"\n";
    //cout<<a<<" "<<b<<"\n";
    if (a<b)
    {

        int l0=anslef[b];
        if (l0==-1)
        {
            cout<<"-1\n";
            exit(0);
        }
        answ+=abs(b-l0);
        used[b]=1;
        b=l0;
    }
    else
    if (a>b)
    {
        int r0=ansrigh[b];
        if (r0==-1)
        {
            cout<<"-1\n";
            exit(0);
        }
        answ+=abs(b-r0);
        used[b]=1;
        b=r0;
    }
    else
        endof=1;
    }
    cout<<answ<<"\n";
    return 0;
}