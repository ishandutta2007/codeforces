#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int maxn = 3e5 + 233;
#pragma GCC optimize(2)
set<int> st;
unordered_map<int,int> ump;
int block, n, m, a[maxn], ans[maxn], cnt, p[maxn], num[maxn];
struct qs{
    int l, r, idx;
}b[maxn];
bool cmp(const qs &x, const qs &y)
{
    return (x.l / block) == (y.l / block) ? x.r < y.r : x.l < y.l;  
}
inline void pls(int x)
{ 
    num[p[a[x]]++]--;
    int t = p[a[x]];
    num[t] ++;
    if(t > cnt) cnt = t;
}
inline void sbs(int x)
{
    num[p[a[x]]--]--;
    int t = p[a[x]];
    num[t] ++;
    while (!num[cnt]) cnt --;
}
int main()
{
    cin >> n >> m;
    block = n / sqrt(m * 2 / 3);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]), st.insert(a[i]);
    for(int i = 1; i <= m; i++)
    {
        scanf("%d%d", &b[i].l, &b[i].r);
        b[i].idx = i;
    }
    int tot = 0;
    for(auto it = st.begin(); it != st.end(); it++)
    {
        ump[*it] = ++ tot; 
    }
    for(int i = 1; i <= n; i++) a[i] = ump[a[i]];
    stable_sort(b + 1, b + 1 + m, cmp);
    int l = 0, r = 0;
    for(int i = 1; i <= m; i++)
    {
        while(b[i].l < l) pls(--l);
        while(b[i].l > l) sbs(l++);
        while(b[i].r < r) sbs(r--);
        while(b[i].r > r) pls(++r);
        int tmp=b[i].r-b[i].l+1;
        ans[b[i].idx] = max(0,cnt*2-tmp-1)+1;
    }
    for(int i = 1; i <= m; i++) printf("%d\n", ans[i]);
}