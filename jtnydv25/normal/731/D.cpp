#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii >
#define vll vector<ll >
#define cps CLOCKS_PER_SEC
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1)
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";
#define slld(t) scanf("%lld",&(t))
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define plld(t) printf("%lld\n",(t))
#define endl "\n"

vi w[500005];
int l[500005];
vii intervals;
pii interval;
int main()
{
    int n,c,a;
    sd(n),sd(c);
    rep(i,1,n+1){
        sd(l[i]);
        rep(j,1,l[i]+1){
            sd(a);
            w[i].eb(a-1);
        }
    }
    interval = mp(0,c-1);
    for(int i = 1;i<n;i++)
    {
        int j = 0;
        while(j<sz(w[i]) && j<sz(w[i+1]) && w[i][j] == w[i+1][j])
            j++;
        if(j == sz(w[i+1]) && sz(w[i])>sz(w[i+1]))
        {
            cout<<-1;
            return 0;
        }

        if(j == sz(w[i]))
            continue;
        int x1 = w[i][j],y1 = w[i+1][j];
        if(x1 < y1)
        {
            intervals.eb(mp(c-y1,c-x1-1));
        }
        else
        {
            int l = max(interval.F,c-x1);
            int r = min(interval.S,c-y1-1);
            if(l > r)
            {
                cout<<-1;
                return 0;
            }
            interval = mp(l,r);
        }
    }
    if(intervals.size() == 0)
    {
        cout<<interval.F;
        return 0;
    }
    sort(all(intervals));
    pii p = intervals[0];
    for(int i = 0;i<p.F;i++)
        if(i>=interval.F && i <= interval.S)
        {
            cout<<i;
            return 0;
        }
    for(int i = 1;i<intervals.size();i++)
    {
        pii q = intervals[i];
        if(q.F > p.S)
        {
            for(int j = p.S+1;j<q.F;j++)
            {
                if(j>=interval.F && j <= interval.S)
                {
                    cout<<j;
                    return 0;
                }
            }
            p = q;
        }
        else
        {
            p.S = max(p.S,q.S);
        }
    }
    for(int i = p.S+1;i<=c-1;i++)
        if(i>=interval.F && i<=interval.S)
        {
            cout<<i;
            return 0;
        }
    cout<<-1;    
}