#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define fi first
#define se second
#define pb push_back

//#define int long long
using namespace std;

int n;
int a[100500];
int ans;
int rad[100500];
int rad2[100500];
string out(int i)
{
    string s;
    if (i>0)
    {
        int lx=(ans-2*rad[i]-1)/2;
        for (int i=1; i<=lx; i++)
            s+=(a[i]+'a'-1);
        for (int j=i-rad[i]; j<=i+rad[i]; j++)
            s+=(a[j]+'a'-1);
        for (int i=n-lx+1; i<=n; i++)
            s+=(a[i]+'a'-1);
        return s;
    }
    i=abs(i);
        int lx=(ans-2*rad2[i])/2;
        for (int i=1; i<=lx; i++)
            s+=(a[i]+'a'-1);
        for (int j=i+1-rad2[i]; j<=i+rad2[i]; j++)
            s+=(a[j]+'a'-1);
        for (int i=n-lx+1; i<=n; i++)
            s+=(a[i]+'a'-1);
        return s;
}

main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
    int ttt;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++)
    {
        string s;
        cin>>s;
        n=s.size();
        for (int i=1; i<=n; i++)
            a[i]=(s[i-1]-'a'+1);
        for (int i=1; i<=n; i++)
        {
            rad[i]=0;
            for (int j=1; ;j++)
            {
                if ((i-j<1) or (i+j>n))
                    break;
                if (a[i+j]!=a[i-j])
                    break;
                rad[i]++;
            }
        }
        for (int i=1; i<n; i++)
        {
            rad2[i]=0;
            for (int j=1; ;j++)
            {
                if ((i+1-j<1) or (i+j>n))
                    break;
                if (a[i+j]!=a[i+1-j])
                    break;
                rad2[i]++;
            }
        }

        int lmx=0;
        for (int i=1; i<=n; i++)
        {
            if (a[i]!=a[n+1-i])
                break;
            lmx=i;
        }
        ans=0;
        int ax=0;
        for (int i=1; i<=n; i++)
        {
            int lx=i-rad[i];
            int rx=i+rad[i];
            if (n-rx+1 < lx)
                lx=n-rx+1;
            if (lx-1<=lmx)
            {
                int a1=2*(lx-1)+2*rad[i]+1;
                if (a1>ans)
                    ans=a1, ax=i;
            }
        }
        for (int i=1; i<n; i++)
        {
//            cout<<i<<" "<<rad2[i]<<"\n";
            int lx=i+1-rad2[i];
            int rx=i+rad2[i];
            if (n-rx+1 < lx)
                lx=n-rx+1;
//            cout<<2*(lx-1)+2*rad2[i]<<"\n";
            if (lx-1<=lmx)
            {
                int a1=2*(lx-1)+2*rad2[i];
                if (a1>ans)
                    ans=a1, ax=-i;
            }
        }
//        cout<<ans<<"\n";
        cout<<out(ax)<<"\n";
    }

    return 0;
}