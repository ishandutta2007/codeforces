#include <bits/stdc++.h>

#define f first
#define s second
#define ll long long
#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)

using namespace std;

const int inf=2e9;
const double eps=1e-9;
const int maxn = 1e3+500, base = 1e9+7,maxm= 1e4+5;

ll a[maxn],b [maxn];
ll f1[maxn][maxn],f2[maxn][maxn];
int main()
{
    int n ;scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",a + i);

    for (int i=0;i<n;i++)
        scanf("%d",b + i);

    for (int l=0;l<n;l++){
        ll _or = a[l];
        for (int r=l;r<n;r++){
            _or |= a[r];
            f1[l][r] = _or;
        }
    }


    for (int l=0;l<n;l++){
        ll _or = b[l];
        for (int r=l;r<n;r++){
            _or |= b[r];
            f2[l][r] = _or;
        }
    }
    ll ans = 0;
    for (int l=0;l<n;l++)
        for (int r =l ;r<n;r++)
            ans = max(ans,f1[l][r] +f2[l][r]);
    cout<<ans;
    return 0;
}