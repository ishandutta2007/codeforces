#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long double
#define pll pair<ll,ll>
#define mp make_pair
set<pll > active;
set<pll > ysorted;
const int maxn = 1e5+10;
pll points[maxn];
ll dist(pll a,pll b)
{
    return sqrt((a.F-b.F)*(a.F-b.F) + (a.S-b.S)*(a.S-b.S));
}
int main()
{
    int n;
    cin>>n;
    int x;
    ll sm = 0;
    ll mindist = (1LL<<60);
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&x);
        sm += x;
        points[i] = mp(i,sm);  
    }
    for(int i = 0;i<n;i++)
    {
        while(!active.empty())
        {
            pll p = *(active.begin());
            if((points[i].F - p.F) > mindist)
            {
                active.erase(p);
                ysorted.erase(mp(p.S,p.F));
            }
            else
            {
                break;
            }
        }
        auto it1 = ysorted.upper_bound(mp(points[i].S+mindist,(1LL<<60))) , it2 = ysorted.upper_bound(mp(points[i].S-mindist-1,(1LL<<60)));

        for(auto it = it2;it!=it1;it++)
        {
            pll p = *it;
            mindist = min(mindist,dist(points[i],mp(p.S,p.F)));
        }
        active.insert(points[i]);
        ysorted.insert(mp(points[i].S,points[i].F));
    }
    cout<<(long long)(mindist*mindist+0.5);
}