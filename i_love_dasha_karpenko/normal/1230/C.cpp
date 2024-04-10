#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct st
{
    long long fi, sc;
};
bool const operator<(const st& a, const st& b)
{
    if (a.fi == b.fi)return a.sc < b.sc;
    return a.fi < b.fi;
}
long long n,nums[10],sum,m,res,dom[10][10],v1,v2,i,j;
set<st> d;
set<st> r;
void F(ll v,ll maxn)
{
    if (v > n)
    {
        d = r;
        for (i = 1; i <= n; i++)
        {
            for (j = i+1; j <= n; j++)
            {
                if (dom[i][j])d.erase({ min(nums[i],nums[j]),max(nums[i],nums[j]) });
            }
        }
        res = max(res,ll(r.size() - d.size()));
        return;
    }
    for (ll i = 0; i <= 1+maxn; i++)
    {
        nums[v] = i;
        F(v + 1, max(maxn, i));
    }
}
int main()
{
    cin >> n>>m;
    for(i=1; i<=m; i++)
    {
        cin >> v1 >> v2;
        dom[v1][v2] = 1;
        dom[v2][v1] = 1;
    }
    for (i = 1; i <= 6; i++)
    {
        for (j = 1; j <= 6; j++)r.insert({ i,j });
    }
    for(i=1; i<=7; i++)
    {
        nums[i]=i-1;
    }
    F(1,0);
    cout<<res<<endl;
    return 0;
}