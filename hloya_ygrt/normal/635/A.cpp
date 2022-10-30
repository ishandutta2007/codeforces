#include <bits/stdc++.h>

#define f first
#define s second
#define ll long long
#define pb push_back
#define pf push_front
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output1.txt","w",stdout)
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)

using namespace std;

const int inf=2e9;
const double eps=1e-9;
const int maxn = 1e5+5, base = 1e9+7,maxm= 1e4+5;
    int a[11][11];
int main()
{
    //files1;
    //files2;
    int r,c,n,k;
    cin >> r >> c >> n >> k;
    for (int i=0;i<n;i++)
    {
        int x,y;
        cin >> x >>y ;
        x--;y--;
        a[x][y] = 1;
    }
    int ans= 0 ;

    for (int i=0;i<r;i++)
    for (int j=0;j<c;j++)
    for (int i1=0;i1<r;i1++)
    for (int j1=0;j1<c;j1++){
        int sum = 0;
        for (int i2=i;i2<=i1;i2++)
            for (int j2=j;j2<=j1;j2++)
                sum += a[i2][j2];
        if (sum >= k)
            ans++;
    }

    cout<<ans;
    return 0;
}