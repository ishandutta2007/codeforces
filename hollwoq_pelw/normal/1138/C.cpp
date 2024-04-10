#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=1007;
const int inf=INT_MAX;
const ll inff=1e18;
const ll mod=1e9+7;
#define pii pair<int,int>
#define mkp make_pair
#define F first
#define S second
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n,m;
int r[maxn],c[maxn];
int a[maxn][maxn],rr[maxn][maxn],cc[maxn][maxn];

int32_t main()
{
    IOS
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
    {
        cin>>a[i][j];
    }
    for (int i=1;i<=n;i++)
    {
        vector<pii> v;
        for (int j=1;j<=m;j++)
        {
            v.pb(mkp(a[i][j],j));
        }
        sort(all(v));
        int last=-1,cnt=0;
        for (pii I:v)
        {
            if (I.F!=last)
            {
                last=I.F;
                cnt++;
            }
            rr[i][I.S]=cnt;
        }
        r[i]=cnt;
    }
    for (int j=1;j<=m;j++)
    {
        vector<pii> v;
        for (int i=1;i<=n;i++)
        {
            v.pb(mkp(a[i][j],i));
        }
        sort(all(v));
        int last=-1,cnt=0;
        for (pii I:v)
        {
            if (I.F!=last)
            {
                last=I.F;
                cnt++;
            }
            cc[I.S][j]=cnt;
        }
        c[j]=cnt;
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
           // cout<<rr[i][j]<<' '<<cc[i][j]<<endl<<endl;
            cout<<max(rr[i][j],cc[i][j])+max(r[i]-rr[i][j],c[j]-cc[i][j])<<" \n"[j==m];
        }
    }
}