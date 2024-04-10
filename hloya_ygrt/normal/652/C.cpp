#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define ll long long
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)
#define pii pair<int,int>


const int maxn = 3e5+500;
const int inf = 1e9;
const double eps = 1e-7;
const int base = 1073676287;
using namespace std;

void bad(){ puts("-1"), exit(0); }

int a[maxn];
int b[maxn];
int nxt[maxn];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i=0;i<n;i++)
        scanf("%d", a + i ),b[ a[i] ] = i, nxt[i] = -1;
    for (int i=0;i<m;i++){

        int f,t;
        scanf("%d %d", &f, &t);
        if (b[f] > b[t])
            swap(f, t);
        nxt [b[t]] = max(nxt[b[t]], b[f]);
    }

    ll ans = 0;

    int l = 0, r = 0;

    while (l < n){

        if ( l > r )
            r = l;

        while (r + 1 < n && nxt[r + 1] < l)
            r++;
        ans += r - l + 1;
        l ++ ;
    }

    cout << ans;
    return 0;
}