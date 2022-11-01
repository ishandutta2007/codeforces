#include <iostream>

using namespace std;

int main()
{
    int n,a1[100],a2[100],b[100],minans=1000000000,d=0,s1[100],s2[100];
    cin>>n;
    for (int i=0;i<n-1;i++)
    {
        cin>>a1[i];
        if (i==0)
            s1[i]=a1[i];
        else
            s1[i]=s1[i-1]+a1[i];
    }

     for (int i=0;i<n-1;i++)
    {
        cin>>a2[i];
        if (i==0)
            s2[i]=a2[i];
        else
            s2[i]=s2[i-1]+a2[i];
    }
    for (int i=0;i<n;i++)
        cin>>b[i];

    for (int i=n;i>=1;i--)
    {
        int t;
        if (i==n)
        {
            t=b[i-1]+s1[i-2];
            if (t<minans)
            {
                d=i;
                minans=t;
            }
        }
        else if(i==1)
        {
            t=s2[n-2]+b[i-1];
            if (t<minans)
            {
                d=i;
                minans=t;
            }
        }
        else
        {
            int sa1=s1[i-2];
            int sa2=s2[n-2]-s2[i-2];
            t=b[i-1]+sa1+sa2;
            if (t<minans)
            {
                d=i;
                minans=t;
            }
        }
    }

    int minans2=1000000000;
       for (int i=n;i>=1;i--)
    {
        int t;
        if (d==i) continue;
        if (i==n)
        {
            t=b[i-1]+s1[i-2];
            if (t<minans2)
            {

                minans2=t;
            }
        }
        else if(i==1)
        {
            t=s2[n-2]+b[i-1];
            if (t<minans2)
            {

                minans2=t;
            }
        }
        else
        {
            int sa1=s1[i-2];
            int sa2=s2[n-2]-s2[i-2];
            t=b[i-1]+sa1+sa2;
            if (t<minans2)
            {

                minans2=t;
            }
        }
    }
    cout<<minans+minans2;
    return 0;
}