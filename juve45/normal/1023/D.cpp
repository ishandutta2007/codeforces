#include <bits/stdc++.h>

using namespace std;

int a[200005],first[200005],last[200005],rmq[30][200005],l[200005];

int main()
{
    ios_base::sync_with_stdio(false);
    int n,q,ok=1,ma=0;
    a[0]=1;
    cin>>n>>q;
    for(int i= 0; i < 200005; i++)
        rmq[0][i] = 1e9;

    for (int i=1;i<=n;i++)
        {
            cin>>a[i];
            if (!first[a[i]])
                first[a[i]]=i;
            last[a[i]]=i;
            if(a[i])
                rmq[0][i]=a[i];
            ma=max(ma,a[i]);
        }
    if (ma==0)
        for (int i=1;i<=n;i++)
        a[i]=q,ma=q;
    if (ma!=q)
        for (int i=1;i<=n;i++)
    {
        if (a[i]==0&&ma!=q)
        {
            a[i]=q;
            ma=q;
        }
    }
    for (int i=1;i<=n;i++)
        if (a[i]==0)
        a[i]=a[i-1];
    for (int i=2;i<=n;i++)
        l[i]=l[i/2]+1;

    for (int i=1; (1<<i)<=n;i++)
        for (int j=1;j+(1<<i)<=n+3;j++)
            rmq[i][j]=min(rmq[i-1][j], rmq[i-1][j+(1<<(i-1))]);
            //if (min(rmq[i-1][j], rmq[i-1][j+(1<<(i-1))])!=0)
            //else rmq[i][j]=max(rmq[i-1][j], rmq[i-1][j+(1<<(i-1))]);

    // cerr << first[2] << ' ' << last[2] << '\n';
    for (int i=1;i<=q;i++)
    {
        int x=first[i];
        int y=last[i];
        int l2=l[y-x+1];
        // cerr << min(rmq[l2][x], rmq[l2][y-(1<<l2)+1]) <<  ' ' << i << '\n';
        if (min(rmq[l2][x], rmq[l2][y-(1<<l2)+1])<i)
            ok=0;
        // cerr << ok << '\n';

    }
    if (ma!=q)
        ok=0;
    if (ok==0)
        cout<<"NO";
    else
    {
        cout<<"YES"<<endl;
        for (int i=1;i<=n;i++)
            cout<<a[i]<<" ";
    }
    return 0;
}

//Long long output!!!
//Check constraints!!!