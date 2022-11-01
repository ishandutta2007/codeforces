#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)
#define pii pair<int,int>
#define ll long long

const int maxn = 2e5+500;
const int inf = 1e9;
const double eps = 1e-7;
const int base = 1073676287;
using namespace std;

bool bad[maxn];
int t[maxn];
set<pair<int,int> > was;
    vector<pii> blocks;
bool can(int j)
{
        if (j % 2){
            if (t[j+1] > t[j] && t[j-1] > t[j]){
                return 1;
            }
        } else
        {
            if (t[j+1] < t[j] && t[j-1] < t[j]){
                return 1;
            }
        }
        return 0;
}

    int n;
void solve1()
{
    ll ans = 0;
    int f = blocks.front().f, s = blocks.front().s;
    for (int i=f;i<=s;i++){
            for (int j = 1; j <= n; j++){
                if (was.find(mp(i,j)) != was.end())
                    continue;
                if (was.find(mp(j,i)) != was.end())
                    continue;
                was.insert(mp(i,j));
                swap(t[i], t[j]);
                bool canj = 0;
                if (j % 2){
                    if (t[j+1] > t[j] && t[j-1] > t[j]){
                        canj = 1;
                    }
                } else
                {
                    if (t[j+1] < t[j] && t[j-1] < t[j]){
                        canj = 1;
                    }
                }

                if (canj){
                    bool cani = 1;
                    for (int k=f;k<=s;k++){
                        if (!can(k))
                            cani = 0;
                    }
                    if (cani)
                        ans++;
                }
                swap(t[i], t[j]);
    }
    }
    cout<<ans;
    exit(0);



}
void solve2()
{
    ll ans = 0;
    int f1 = blocks.front().f, s1 = blocks.front().s;
    int f2 = blocks.back().f, s2 = blocks.back().s;
    for (int i = f1; i <= s1; i++)
    for (int j = f2; j <= s2; j++){
            if (was.find(mp(i,j)) != was.end())
                continue;
            if (was.find(mp(j,i)) != was.end())
                    continue;
            was.insert(mp(i,j));
        swap(t[i], t[j]);
        bool c = 1;
        for (int k=f1;k<=s1;k++)
            if (!can(k))
                c = 0;
        for (int k=f2;k<=s2;k++)
            if (!can(k))
                c = 0;
        swap(t[i], t[j]);
        if (c == 1)
            ans ++;
    }
    cout<<ans;
    exit(0);
}
int main()
{
    //files1;
    scanf("%d", &n);
    for (int i=1;i<=n;i++)
        scanf("%d",t + i);
    t[0] = inf;
    t[n+1] = ((-1) * ( (n + 1) % 2)) * inf;
    if (t[n+1] == 0)
        t[n+1] = inf;
    for (int i=1;i<=n;i++){
        if (i % 2){
            if (t[i-1] <= t[i] || t[i+1] <= t[i]){
                bad[i] = 1;
            }
        } else
        {
            if (t[i-1] >= t[i] || t[i+1] >= t[i]){
                bad[i] = 1;
            }
        }
    }
    int cnt = 0;
    int mxsz = 0;
    int p = -1;
    for (int i=1;i<=n + 1;i++){
        if (bad[i] && p == -1){
            p = i;
            continue;
        }
        if (!bad[i] && p != -1){
            blocks.pb(mp(p, i - 1));
            mxsz = max(mxsz, i - p);
            cnt++;
            p = -1;
        }
    }
    if (mxsz > 6 || cnt > 2){
        cout<<0;
        return 0;
    }

    if (cnt == 1){
        solve1();
    } else
    {
        solve2();
    }
    return 0;
}