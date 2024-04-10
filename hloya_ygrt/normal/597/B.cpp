#include <bits/stdc++.h>

#define f first
#define s second
#define ll long long
#define ld long double
#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)


using namespace std;

const int inf=2e9;
const double eps=1e-9;
const int maxn = 1e6+ 5, base = 1e9+7;

vector<pair<int,int> > a;

bool cmp(pair<int,int> x, pair<int,int> y)
{
    if (x.s == y.s){
        return x.f < y.f;
    }
    return x.s < y.s;
}
unordered_map<int,int> t;

void add(ll i,int x)
{
    while (i < inf)
    {
        t[i] = max(t[i], x);
        i += i & (-i);
    }
}

int mx(int r)
{
    int ans = 0;
    while (r > 0)
    {
        if (t.count(r))
            ans = max(ans, t[r]);
        r -= r & (-r);
    }
    return ans;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++){
        int f,t;
        scanf("%d %d", &f, &t);
        a.pb(mp(f,t));
    }

    sort(a.begin(), a.end(), cmp);
    int ans = 0;
    for (int i=0;i<n;i++){
        int l = a[i].f, r = a[i].s;
        int dp = mx(l - 1) + 1;
        add(r, dp);
        ans = max(ans, dp);
    }

    cout << ans;
    return 0;
}