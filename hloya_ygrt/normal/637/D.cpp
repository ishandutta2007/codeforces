#include <bits/stdc++.h>

#define f first
#define s second

#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)

using namespace std;

const int inf=2e9;
const int sz = 3;
const double eps=1e-9;
const int maxn = 2e5+500, base = 1e9+7,maxm= 10;

int t[maxn*4];

void update(int v,int tl,int tr,int pos)
{
    if (tl == tr)
        t[v] = tl;
    else
    {
        int tm = ( tl + tr ) >> 1;
        if (pos <= tm)
            update(v*2+0,tl+0,tm,pos);
        else
            update(v*2+1,tm+1,tr,pos);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}

int find_first(int v,int tl,int tr,int l,int r)
{
    if (l > r)
        return -1;
    if (tl == l && tr == r)
        return t[v];
    int tm = (tl + tr) / 2;
    return max(find_first(v*2,tl,tm,l,min(tm,r)), find_first(v*2+1,tm+1,tr,max(tm+1,l),r));
}

int a[maxn];
int par[maxn];

void bad()
{
    cout<<"IMPOSSIBLE";
    exit(0);
}

set<int> used;
int main()
{
    //files1;
    int n,m,s,d;
    scanf("%d %d %d %d",&n,&m,&s,&d);
    for (int i=0;i<4*maxn;i++)
        t[i] = -1;
    for (int i=0;i<n;i++){
        scanf("%d",a + i);
        used.insert(a[i]);
    }
    sort(a, a + n);
    int last;
    if (a[0] - 1>= s){
        last = -1;
        for (int i=0;i<n-1;i++){
            if (a[i+1] - a[i] - 2 >= s && a[i] + 1 - (a[0] - 1) <= d){
                last = i;
                break;
            }
        }

        if (last == -1){
            if (a[n-1] + 1 - (a[0] - 1) <= d)
                last = n-1;
            else
                bad();
        }
        par[last] = -1;
        update(1,0,n-1,last);
    }
    else
        bad();

    for (int i=last + 1; i < n; i++){
            if (used.find(a[i]+1) != used.end())
                continue;
            if (i != n-1 && a[i+1] - a[i] - 2 < s)
                continue;

            int l = 0 , r = i - 1;
            while(r - l > 1)
            {
                int m = (l + r) / 2;
                if ( a[i] - a[m+1] + 2 <= d)
                    r = m;
                else
                    l = m;
            }
            if (a[i] - a[r+1] + 2 > d){ // + 2
                continue;
            }
            int ans = l;
            if (a[i] - a[ans+1] + 2 > d)
                ans = r;
            int from = find_first(1,0,n-1,ans, i-1);
            if (from == -1)
                continue;
            par[i] = from;
            update(1,0,n-1,i);
    }
    vector<pair<int,int> > ans; // len type (0 run 1 jump)
    if (find_first(1,0,n-1,n-1,n-1) == -1)
        bad();

    ans.pb(mp(m - a[n-1] - 1, 0));
    int in = n-1;
    while (in != -1)
    {
        //cerr<<in<<endl;
        int next = par[in];

        ans.pb(mp(a[in] - a[next + 1] + 2, 1));

        if (next != -1)
            ans.pb(mp(a[next+1]-a[next]-2, 0));
        in = next;
    }
    //return 0; // del

    ans.pb(mp(a[0]-1, 0));
    reverse(ans.begin(), ans.end());
    if (ans.back().f == 0)
        ans.pop_back();
    if (ans.front().f == 0)
        ans.erase(ans.begin());
    for (int i=0;i<ans.size();i++){
        if (ans[i].s == 0)
            printf("RUN ");
        else
            printf("JUMP ");
        printf("%d\n",ans[i].f);
    }
}