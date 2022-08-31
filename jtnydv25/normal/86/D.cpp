#include <bits/stdc++.h>
using namespace std;

#define slld(t) scanf("%lld",&(t))
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define plld(t) printf("%lld\n",(t))
#define ll long long
const int maxn = 1e6+10;
const int sqmaxn = 1010;
int f[maxn],a[maxn];
ll ans;
void add(int i)
{
    ans += i*1ll*(2*f[i] + 1);
    f[i]++;
}
void remove(int i)
{
    if(!f[i])
        return;
    ans -= i*1ll*(2*f[i] - 1);
    f[i] --;
}

#define eb emplace_back
#define F first
#define S second

vector< pair<int,pair<int,int> > > queries[sqmaxn+10];
ll st[maxn];
int main()
{
    cin.tie(0);
    cout.tie(0);
    std::ios::sync_with_stdio(false);
    memset(f,0,sizeof f);
    memset(a,0,sizeof a);
    int n,q;
    cin>>n>>q;
    for(int i = 0;i<n;i++)
        cin>>a[i];

    int d = ((int)sqrt(n) + 4);
    while(d*d < n)
        d++;
    for(int i = 0;i<q;i++)
    {
        int l,r;
        cin>>l>>r;
        l--;
        r--;

        queries[l/d].eb(make_pair(r,make_pair(l,i)));
    }
    for(int i = 0;i<=d;i++){
        if(queries[i].empty())
            continue;
        sort(queries[i].begin(),queries[i].end());
        ans = 0;
        memset(f,0,sizeof f);
        for(int j = queries[i][0].S.F;j<=queries[i][0].F;j++)
            add(a[j]);
        st[queries[i][0].S.S] = ans;
        int l = queries[i][0].S.F,r=queries[i][0].F;
        for(int j = 1;j<queries[i].size();j++)
        {
            int l1 = queries[i][j].S.F,r1 = queries[i][j].F;
            if(l1 > l)
            {
                for(int k = l;k<min(l1,r+1);k++)
                    remove(a[k]);
            }
            else
            {
                for(int k = l1;k<l;k++)
                    add(a[k]);
            }
            for(int k = max(r+1,l1);k<=r1;k++)
                add(a[k]);
            st[queries[i][j].S.S] = ans;
            l = l1;r=r1;
        }
    }
    for(int i = 0;i<q;i++)
        cout<<st[i]<<"\n";
}