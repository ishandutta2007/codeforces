#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    long long prm[100100], prn[100100];
    cin>>n>>m;
    prm[0]=0;
    prn[0]=0;
    int q;
    for (int i=1; i<=n; i++)
    {
        cin>>q;
        prn[i]=prn[i-1]+q;
    }
    for (int i=1; i<=m; i++)
    {
        cin>>q;
        prm[i]=prm[i-1]+q;
    }
    prm[m+1]=1000000000000000000;
    prn[n+1]=1000000000000000000;
    int ans=0;
    int lt=1;
    int rt=1;
    int lt0=1;
    while (lt<=n)
    {
        int l,r;
        l=lt0;
        r=m;
        while ((r-l)>10)
        {
            int mid=((l+r)/2);
            if (prm[mid]-prm[lt0-1]>prn[rt]-prn[lt-1])
                r=mid;
            else
                l=mid;
        }
        while (prm[l]-prm[lt0-1]<prn[rt]-prn[lt-1])
            l++;
        if (prm[l]-prm[lt0-1]==prn[rt]-prn[lt-1])
        {
            ans++;
            lt=rt+1;
            rt++;
            lt0=l+1;
        }
        else
            rt++;
    }
    cout<<ans<<"\n";
    return 0;
}