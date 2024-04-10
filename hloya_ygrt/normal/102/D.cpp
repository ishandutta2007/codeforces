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
const int maxn = 1e5+500, base = 1e9+7,maxm= 1e4+5;

pair<int,int> r[maxn];
unordered_map<int,int> t;

int sum(int i)
{
    int ans = 0;

    while (i > 0)
    {
        if (t.find(i) != t.end()){
            ans += t[i];
            ans %= base;
        }
        i -= i & (-i);
    }
    return ans;
}

void add(int i,int x)
{
    while (i <= inf/2 + 1)
    {
        if (t.find(i) == t.end())
            t[i] = x;
        else
        {
            t[i] += x;
            t[i] %= base;
        }
        i += i & (-i);
    }
}
int main()
{
    int n, m;
    scanf("%d %d",&n,&m);
    for (int i=0;i<m;i++){
        scanf("%d %d",&r[i].s,&r[i].f);
        r[i].f++;
        r[i].s++;
    }
    n++;
    sort(r, r + m);
    for (int i=0;i<m;i++)
        swap(r[i].f, r[i].s);
    t.max_load_factor(0.25);
    t.reserve(1024);

    add(1, 1);
    for (int i=0;i<m;i++){
        int start = r[i].f;
        int finish = r[i].s;
        int cnt = sum(finish - 1) - sum(start - 1) + base;
        cnt %= base;
        add(finish, cnt);
    }
    printf("%d", (sum(n) - sum(n-1) + base) % base);
}