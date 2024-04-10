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
const int maxn = 1e5+500, base = 1e9+7;
    int a[maxn];

struct qry
{
    int l,r,it;
    qry(int l,int r,int it):l(l),r(r),it(it){}
    qry(){}

    bool operator < (const qry &t) const
    {
        return r < (t.r);
    }
};

vector<qry> asks[350];

int get_sqr(int x)
{
    ll l = 0,r = x;
    while (r-l>1)
    {
        ll m = (l + r) >> 1;

        if (m*m <= 1LL*x)
            l = m;
        else
            r = m;
    }
    if (r*r<=x)
        l++;

    return (int)l;
}

int answers[maxn];
int cur[maxn];
int good = 0;
int t;

void update(int it)
{
    t = a[it];
    if (t >= maxn)
       return;
    if (cur[t] == t)
        good--;
    cur[t]++;
    if (cur[t] == t)
        good++;
}

int main()
{
    int n,m;
 //   files1;
    //files2;
    scanf("%d %d",&n,&m);
    for (int i=0;i<n;i++){
        scanf("%d",a + i);
    }
    //cerr<<get_sqr(2);
  //  cerr<<' '<<get_sqr(10);
   //cout<<get_sqr(maxn-500)<<endl;
    for (int i=0;i<m;i++){
        int l,r;
        scanf("%d %d",&l,&r);
        l--;
        r--;

        asks[get_sqr(l)].pb(qry(l,r,i));
    }
    for (int i=0;i<350;i++)
        sort(asks[i].begin(),asks[i].end());

    for (int i=0;i<350;i++){
       if (asks[i].empty())
            continue;
        memset(cur,0,sizeof(cur));
        good = 0;
        int l0 = asks[i][0].l;
        int r0 = asks[i][0].r;
        for (int j=l0;j<=r0;j++){
            update(j);
        }

        answers[asks[i][0].it] = good;
        int l = l0,r = r0;
        for (int k = 1; k < asks[i].size();k++){
            l0 = asks[i][k].l;
            r0 = asks[i][k].r;
            int it = asks[i][k].it;

            while (r < r0){
                update(r+1);r++;
            }
            while (l > l0){
                update(l-1);l--;
            }
            while (l<l0){
                t = a[l];
                if (t >= maxn)
                    continue;
                if (cur[t] == t)
                    good--;
                cur[t]--;
                if (cur[t] == t)
                    good++;
                  l++;
            }
            answers[it] = good;
        }

    }

    for(int i=0;i<m;i++)
        printf("%d\n",answers[i]);
    return 0;
}