#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define fi first
#define se second
#define pb push_back

#define int long long
using namespace std;

int n;
int a[1000500];
int ans;
int rad[1000500];
int rad2[1000500];
int has[1000500];
int has1[1000500];
int pw[1000500];
int mod=1e9+9;

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

int h(int l, int r, int g)
{
    if (g==1)
    {
        return (((has[r]-has[l-1]*pw[r-l+1])%mod)+mod)%mod;
    }
    else
    {
        l=n+1-l;
        r=n+1-r;
        swap(l, r);
        return (((has1[r]-has1[l-1]*pw[r-l+1])%mod)+mod)%mod;
    }
}

bool pal(int i, int r, int g)
{
    if (g==1)
    {
        if (i+r>n)
            return false;
        if (i-r<1)
            return false;
        return h(i-r, i+r, 1)==h(i-r, i+r, 2);
    }
    if (i+r>n)
        return false;
    if (i+1-r<1)
        return false;
    return h(i+1-r, i+r, 1)==h(i+1-r, i+r, 2);
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
        pw[0]=1;
        for (int i=1; i<=n; i++)
            pw[i]=29*pw[i-1], pw[i]%=mod;
        for (int i=1; i<=n; i++)
            has[i]=29*has[i-1]+a[i], has[i]%=mod;
        for (int i=1; i<=n; i++)
            has1[i]=29*has1[i-1]+a[n+1-i], has1[i]%=mod;

        for (int i=1; i<=n; i++)
        {
            int l=0;
            int r=n+1;
            while (r-l>1)
            {
                int m=(l+r)/2;
                if (pal(i, m, 1))
                    l=m;
                else
                    r=m;
            }
            rad[i]=l;
        }
        for (int i=1; i<n; i++)
        {
            int l=0;
            int r=n+1;
            while (r-l>1)
            {
                int m=(l+r)/2;
                if (pal(i, m, 2))
                    l=m;
                else
                    r=m;
            }
            rad2[i]=l;
        }
//        for (int i=1; i<=n; i++)
//        {
//            rad[i]=0;
//            for (int j=1; ;j++)
//            {
//                if ((i-j<1) or (i+j>n))
//                    break;
//                if (a[i+j]!=a[i-j])
//                    break;
//                rad[i]++;
//            }
//        }
//        for (int i=1; i<n; i++)
//        {
//            rad2[i]=0;
//            for (int j=1; ;j++)
//            {
//                if ((i+1-j<1) or (i+j>n))
//                    break;
//                if (a[i+j]!=a[i+1-j])
//                    break;
//                rad2[i]++;
//            }
//        }

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