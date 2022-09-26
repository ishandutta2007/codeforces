#include <bits/stdc++.h>

#define int long long
#define fi first
#define se second
#define pb push_back

using namespace std;

string s;

int t[100500];
int k, p1, p2;

bool ch(int a, int b, int s)
{
    return ( (s>=a-b*k) and (s<=a*k-b) );
}

string f(int q)
{
    if (q==1)
        return " + ";
    else
        return " - ";
}

main()
{
    int n=1;
    t[1]=1;
    p1=1;
    p2=0;
    cin>>s;
    while (s!="=")
    {
        n++;
        cin>>s;
        if (s!="=")
        {
            if (s=="+")
                t[n]=1, p1++;
            else
                t[n]=-1, p2++;
            cin>>s;
        }
    }
//    cout<<p1<<" "<<p2<<"\n";
    n--;
    cin>>k;
    if (!ch(p1, p2, k))
        cout<<"Impossible\n", exit(0);
    cout<<"Possible\n";
    int s0=k;
    int a=p1, b=p2;
    for (int i=1; i<n; i++)
    {
        if (t[i]==1)
        {
            if (ch(a-1, b, s0-1))
                cout<<1<<f(t[i+1]), a--, s0--;
            else
                cout<<k<<f(t[i+1]), a--, s0-=k;
        }
        else
        {
            if (ch(a, b-1, s0+1))
                cout<<1<<f(t[i+1]), b--, s0++;
            else
                cout<<k<<f(t[i+1]), b--, s0+=k;
        }
    }
    cout<<abs(s0)<<" = "<<k<<"\n";
    return 0;
}