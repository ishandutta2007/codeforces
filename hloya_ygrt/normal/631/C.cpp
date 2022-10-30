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
#define pii pair<int,int>
using namespace std;

const int inf=2e9;
const double eps=1e-9;
const int maxn = 2e5+500, base = 1e9+7,maxm= 1e4+5;

struct sost
{
    pii que;
    int it;
    sost(){}
    sost(pii que,int it):que(que),it(it){}
    bool operator < (const sost & T) const
    {
        if (que.s < T.que.s)
            return 1;
        if (T.que.s < que.s)
            return 0;
        if (it < T.it)
            return 1;
        return 0;
    }
};
sost t[maxn];

pii q[maxn];

void add(int i,sost x)
{
    sost ans = x;
    while (i < maxn)
    {
        t[i] = max(ans,t[i]);
        i += i & (-i);
    }
}

sost mx(int r)
{
    sost ans = t[r];
    while (r > 0)
    {
        ans = max(ans,t[r]);
        r -= r& (-r);
    }
    return ans;
}
int a[maxn];
int ans[maxn];
int main()
{
   // files1;
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",a + i);
    }

    for (int i=0;i<m;i++){
        scanf("%d %d",&q[i].f,&q[i].s);
        q[i].s -- ;
    }

    int start = 0;
    for (int i=1;i<m;i++){
        if (q[i].s >= q[start].s)
            start = i;
    }
    vector<int> work;
    for (int i=0;i<=q[start].s;i++)
        work.pb(a[i]);

    for (int i=q[start].s+1;i<n;i++)
        ans[i] = a[i];
    int open = q[start].s ;

    sort(work.begin(),work.end());
    //if (q[start].f == 2)
    //    reverse(work.begin(),work.end());
    deque<int> in;
    for (int i=0;i<work.size();i++)
        in.pb(work[i]);

    for (int i=start+1;i<m;i++){
        add(m - i , sost(q[i],i));
    }

    while (1)
    {
        int type = q[start].f;
        if (start == m-1)
        {
            while (!in.empty())
            {
                if (type == 2){
                    ans[open] = in.front();
                    open--;
                    in.pop_front();
                } else
                {
                    ans[open] = in.back();
                    open--;
                    in.pop_back();
                }
            }
            break;
        }
        sost next = mx( m - start - 1 );
        int finish = next.que.s;

        for (int i = finish + 1; i <= q[start].s ; i++){
                if (type == 2){
                    ans[open] = in.front();
                    open--;
                    in.pop_front();
                } else
                {
                    ans[open] = in.back();
                    open--;
                    in.pop_back();
                }
        }
        start = next.it;

    }

    for(int i=0;i<n;i++)
        cout<<ans[i]<<' ';
    return 0;
}