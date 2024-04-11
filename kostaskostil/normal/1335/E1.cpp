#include <bits/stdc++.h>

using namespace std;

//#define int long long

const int nmax=2e5+100;
int a[nmax];
int c[201];
int cnt[nmax][201];
vector<int> pos[201];
int n;

int mx(int l, int r)
{
    int ans=0;
    for (int i=1; i<=200; i++)
        ans=max(ans, cnt[r][i]-cnt[l-1][i]);
//    cout<<"mx: "<<l<<" "<<r<<" "<<ans<<"\n";
    return ans;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    for (int i=0; i<t; i++)
    {
        cin>>n;
        for (int i=1; i<=200; i++)
            pos[i].clear();
        for (int i=1; i<=n; i++)
            cin>>a[i];
        for (int i=1; i<=200; i++)
            c[i]=0, cnt[0][i]=0, pos[i].push_back(0);
        for (int i=1; i<=n; i++)
        {
            int x=a[i];
            c[x]++;
            pos[x].push_back(i);
        }
        for (int i=1; i<=n; i++)
            for (int j=1; j<=200; j++)
                if (a[i]==j)
                    cnt[i][j]=cnt[i-1][j]+1;
                else
                    cnt[i][j]=cnt[i-1][j];
        int ans=mx(1, n);
        for (int i=1; i<=200; i++)
        {
            int v=c[i];
            for (int j=1; 2*j<=v; j++)
            {
                int l=pos[i][j];
                int r=pos[i][v+1-j];
//                cout<<i<<" "<<j<<" "<<2*j + mx(l+1, r-1)<<"\n";
                ans=max(ans, 2*j + mx(l+1, r-1));
            }
        }
        cout<<ans<<"\n";
//        if (n==1){
//            cout<<1<<"\n";
//            continue;
//        }
//        lt[1]=0;
//        for (int i=2; i<=n; i++)
//            if (a[i]==a[i-1])
//                lt[i]=lt[i-1];
//            else
//                lt[i]=i-1;
//        rt[n]=n+1;
//        for (int i=n-1; i>=1; i--)
//            if (a[i]==a[i+1])
//                rt[i]=rt[i+1];
//            else
//                rt[i]=i+1;
//        int ans=0;
//        for (int i=1; i<=n; i++){
//            int l=lt[i];
//            int r=rt[i];
//            ans=max(ans, r-l-1);
//            if ((l>0) and (r<=n))
//                if (a[l]==a[r])
//                {
//                    int l2=lt[l];
//                    int r2=rt[r];
//                    int dist=min(l2-lt[l], rt[r]-r2);
//                    ans=max(ans, 2*dist+(r-l-1));
//                }
//        }
//        cout<<ans<<"\n";
    }
    return 0;
}