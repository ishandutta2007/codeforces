#include <iostream>
#include <cstdio>

using namespace std;

const int maxn=100005;

int k1[maxn],k2[maxn];

int main()
{
    char c;
    while (scanf("%c",&c)==1)
    {
        if (c<'0' || c>'9') break;
        k1[c-48]++;
        k2[c-48]++;
    }
    int minans=0;
    int minansk0=0;
    int minansf=10;
    for (int k0=0;k0<=k1[0];k0++)
    {
        k1[0]-=k0;
        k2[0]-=k0;
        for (int f=1;f<10;f++) if (k1[f]>0 && k2[10-f]>0)
        {
            k1[f]--;
            k2[10-f]--;
            int ans=k0+1;
            for (int i=0;i<10;i++)
            {
                ans+=min(k1[i],k2[9-i]);
            }
            if (ans>minans)
            {
                minans=ans;
                minansk0=k0;
                minansf=f;
            }
            k1[f]++;
            k2[10-f]++;
        }
        if (k0>minans)
        {
            minans=k0;
            minansk0=k0;
            minansf=10;
        }
        k1[0]+=k0;
        k2[0]+=k0;
    }
    //cout << minans << ' ' << minansf << ' ' << minansk0 << endl;
    if (minansf==10)
    {
        k1[0]-=minansk0;
        k2[0]-=minansk0;
        for (int i=0;i<10;i++)
            for (int j=1;j<=k1[i];j++) cout << i;
        for (int i=1;i<=minansk0;i++) cout << 0;
        cout << endl;
        for (int i=0;i<10;i++)
            for (int j=1;j<=k2[i];j++) cout << i;
        for (int i=1;i<=minansk0;i++) cout << 0;
        cout << endl;
        return 0;
    }
    k1[0]-=minansk0;
    k2[0]-=minansk0;
    k1[minansf]--;
    k2[10-minansf]--;
    for (int i=0;i<10;i++)
        for (int j=1;j<=k1[i]-min(k1[i],k2[9-i]);j++) cout << i;
    for (int i=0;i<10;i++)
        for (int j=1;j<=min(k1[i],k2[9-i]);j++) cout << i;
    cout << minansf;
    for (int i=1;i<=minansk0;i++) cout << 0;
    cout << endl;
    for (int i=0;i<10;i++)
        for (int j=1;j<=k2[i]-min(k1[9-i],k2[i]);j++) cout << i;
    for (int i=9;i>=0;i--)
        for (int j=1;j<=min(k1[9-i],k2[i]);j++) cout << i;
    cout << 10-minansf;
    for (int i=1;i<=minansk0;i++) cout << 0;
    cout << endl;
    return 0;
}