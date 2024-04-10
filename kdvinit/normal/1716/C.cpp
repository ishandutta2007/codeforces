/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int M = 2e5 + 100;
int a[3][M];
int m;

bool check(int k)
{
    int wt = k-((2*m)-1);
    if(wt<0) return false;

    int adi[3][m+1];        //Add i
    int sbi[3][m+1];        //Sub i

    for(int i=1; i<=2; i++)
    {
        adi[i][m]=a[i][m]+m;
        sbi[i][m]=a[i][m]-m;

        for(int j=m-1; j>=1; j--)
        {
            int cur=a[i][j]+j;
            adi[i][j]=max(cur, adi[i][j+1]);

            cur=a[i][j]-j;
            sbi[i][j]=max(cur, sbi[i][j+1]);
        }
    }

    int tim=wt;

    //cout<<k<<" -> ";

    for(int j=1; j<=m; j++)
    {
        //cout<<j<<" ";
        if(j%2==1)
        {
            int suf1 = sbi[1][j]+j;
            int suf2 = adi[2][j]-(2*m)+(j-1);

            if(suf1<tim && suf2<tim) return true;

            if(a[1][j]>=tim) return false;
            if(a[2][j]>=tim+1) return false;
        }
        else
        {
            int suf1 = sbi[2][j]+j;
            int suf2 = adi[1][j]-(2*m)+(j-1);

            if(suf1<tim && suf2<tim) return true;

            if(a[2][j]>=tim) return false;
            if(a[1][j]>=tim+1) return false;
        }

        tim+=2;
    }

    return false;
}

void solve()
{
    cin>>m;
    for(int i=1; i<=2; i++)
    {
         for(int j=1; j<=m; j++) cin>>a[i][j];
    }

    a[1][1]--;
    int l=0;
    int r=1e10;

    while(l+1!=r)
    {
        int mid=(l+r)/2;
        if(check(mid)) r=mid;
        else l=mid;
        //cout<<endl;
    }

    cout<<r<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}