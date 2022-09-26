#include <bits/stdc++.h>

using namespace std;

int a[500];

signed main()
{
    int n,n1,n2,n3;
    n1=0;
    n2=0;
    n3=0;
    string s1,s2,s3;
    cin>>n;
    cin>>s1>>s2>>s3;
    if (n>1000000)
    {
        cout<<"Draw\n";
        return 0;
    }

    for (int i=0; i<500; i++)
        a[i]=0;
    for (int i=0; i<s1.size(); i++)
        a[int(s1[i])]++;
    for (int i=0; i<500; i++)
        n1=max(n1,a[i]);

    for (int i=0; i<500; i++)
        a[i]=0;
    for (int i=0; i<s2.size(); i++)
        a[int(s2[i])]++;
    for (int i=0; i<500; i++)
        n2=max(n2,a[i]);

    for (int i=0; i<500; i++)
        a[i]=0;
    for (int i=0; i<s3.size(); i++)
        a[int(s3[i])]++;
    for (int i=0; i<500; i++)
        n3=max(n3,a[i]);

    if (n!=1)
    {
        n1=min(int(s1.size()), n1+n);
        n2=min(int(s2.size()), n2+n);
        n3=min(int(s3.size()), n3+n);
    }
    else
    {
        if (n1==s1.size())
            n1--;
        else
            n1++;

        if (n2==s2.size())
            n2--;
        else
            n2++;

        if (n3==s3.size())
            n3--;
        else
            n3++;
    }

    if ((n1>n2) and (n1>n3))
    {
        cout<<"Kuro\n";
        return 0;
    }
    if ((n2>n3) and (n2>n1))
    {
        cout<<"Shiro\n";
        return 0;
    }
    if ((n3>n2) and (n3>n1))
    {
        cout<<"Katie\n";
        return 0;
    }
    cout<<"Draw\n";
    return 0;
}