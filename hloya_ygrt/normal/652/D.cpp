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


const int maxn = 5e5+500;
const int inf = 1e9;
const double eps = 1e-7;
const int base = 1073676287;
using namespace std;

void bad(){ puts("-1"), exit(0); }

struct triple
{
    int l, r, it;
    bool operator < (const triple & x) const
    {
        return l < x.l;
    }
    triple(){}
    triple(int l,int r,int it):l(l), r(r), it(it){}
};

vector<triple> a;

int t[maxn];

void add(int i,int x)
{
    while (i < maxn)
    {
        t[i] += x;
        i += i & (-i);
    }
}

int sum(int r)
{
    int ans = 0;
    while (r > 0)
    {
        ans += t[r];
        r -= r & (-r);
    }
    return ans;
}

vector<int> work;
map<int,int> sot;
int answers[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++){
        int l,r;
        scanf("%d %d", &l, &r);
        a.pb(triple(l, r, i));

        work.pb(l);
        work.pb(r);
    }

    sort(work.begin(), work.end());
    for (int i=0;i<work.size();i++)
        sot[work[i]] = sot.size() + 1;

    sort(a.begin(), a.end());

    for (int i=0;i<a.size();i++){
        a[i].l = sot[a[i].l];
        a[i].r = sot[a[i].r];
    }
    work.clear();

    for (int i=0;i<a.size();i++){
        add(a[i].r, 1);
    }

    for (int i=0;i<a.size();i++){
        answers[a[i].it] = sum(a[i].r - 1);
        add(a[i].r, -1);
    }
    for (int i=0;i<n;i++){
        printf("%d\n", answers[i] );
    }
    return 0;
}