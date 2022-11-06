#include<bits/stdc++.h>

using namespace std;

typedef long long li;
const li INF64 = li(1e18);
const int N = 500043;

li f[N];

li get(int x)
{
    li ans = 0;    
    for (; x >= 0; x = (x & (x + 1)) - 1)
        ans += f[x];
    return ans;
}

void inc(int x, li d)
{
    for (; x < N; x = (x | (x + 1)))
        f[x] += d;    
}

li get(int l, int r)
{
    return get(r) - get(l - 1);
}

li dp[N];
int a[N], b[N], p[N];
int n, m;

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < n; i++)
        scanf("%d", &p[i]);
    scanf("%d", &m);
    for(int i = 0; i < m; i++)
        scanf("%d", &b[i]);

    for(int i = 0; i < n; i++)
        dp[i] = -INF64;
    map<int, vector<int> > pos;
    for(int i = 0; i < n; i++)
        pos[a[i]].push_back(i);
    set<pair<int, int> > q;
    for(int i = 0; i < n; i++)
        q.insert(make_pair(a[i], i));
    
    for(auto x : pos[b[0]])
        dp[x] = p[x];
    while(!q.empty() && q.begin()->first <= b[0])
    {
        int k = q.begin()->second;
        q.erase(q.begin());
        if(p[k] > 0)
            inc(k, p[k]);
    }  

    for(int i = 1; i < m; i++)
    {
        int i1 = b[i - 1], i2 = b[i];
        vector<int> both_pos;
        for(auto x : pos[i1])
            both_pos.push_back(x);
        for(auto x : pos[i2])
            both_pos.push_back(x);
        li best = -INF64;
        int last = -1;
        sort(both_pos.begin(), both_pos.end());
        for(auto x : both_pos)
        {
            best += get(last + 1, x);
            last = x;
            if(a[x] == i1)
                best = max(best, dp[x]);
            else
                dp[x] = best + p[x];
        }
        while(!q.empty() && q.begin()->first <= i2)
        {
            int k = q.begin()->second;
            q.erase(q.begin());
            if(p[k] > 0)
                inc(k, p[k]);
        }
    }

    li best_dp = -INF64;
    for(int i = 0; i < n; i++)
        if(a[i] == b[m - 1])
            best_dp = max(best_dp, dp[i] + get(i + 1, n - 1));
    li ans = 0;
    for(int i = 0; i < n; i++)
        ans += p[i];
    ans -= best_dp;
    if(ans > li(1e15))
        puts("NO");
    else     
        printf("YES\n%lld\n", ans);
    
}