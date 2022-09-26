#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
using namespace std;

int x, k, n, m;

int ans(int s1, int f1, int x1, int s2, int f2, int x2)
{
    int a[100][3];
    a[1][0]=x1;
    a[1][1]=s1;
    a[1][2]=f1;

    a[2][0]=x2;
    a[2][1]=s2;
    a[2][2]=f2;

    for (int i=3; i<=k; i++)
    {
        a[i][1]=a[i-2][1];
        a[i][2]=a[i-1][2];
        a[i][0]=a[i-1][0]+a[i-2][0];

        if (a[i-2][2]==1 and a[i-1][1]==2)
            a[i][0]++;

        if (a[i][0]>x)
            return -1;
    }

    return a[k][0];
}

string mul(string w, int a)
{
    string ans="";
    for (int i=1; i<=a; i++)
        ans=ans+w;
    return ans;
}

string fr(int q)
{
    if (q==0)
        return "B";
    if (q==1)
        return "A";
    if (q==2)
        return "C";
    cout<<1/0<<"\n";
}

string s(int t, int s, int f, int x)
{
    if (2*x > t)
        return "-";
    if (2*x == t)
    {
        if (s!=1 or f!=2)
            return "-";
        return mul("AC", x);
    }
    if (2*x +1 == t)
    {
        if (f==2)
            return fr(s)+mul("AC", x);
        if (s==1)
            return mul("AC", x)+fr(f);
        return "-";
    }
    return fr(s)+mul("AC",x)+mul("B", t-2*x-2)+fr(f);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>k>>x>>n>>m;

    for (int i1=0; i1<3; i1++)
        for (int i2=0; i2<3; i2++)
            for (int i3=0; i3<3; i3++)
                for (int i4=0; i4<3; i4++)
    for (int i5=0; i5<=100; i5++)
        for (int i6=0; i6<=100; i6++)
            if (ans(i1, i2, i5, i3, i4, i6)==x)
            {
                string s1=s(n, i1, i2, i5);
                string s2=s(m, i3, i4, i6);
                if (s1!="-")
                    if (s2!="-")
                        cout<<s1<<"\n"<<s2<<"\n", exit(0);
            }
    cout<<"Happy new year!\n";
    return 0;
}