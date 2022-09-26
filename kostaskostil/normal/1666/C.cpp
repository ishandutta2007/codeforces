#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x1,y1,x2,y2,x3,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    int xl=min({x1,x2,x3});
    int xr=max({x1,x2,x3});
    int xm=x1+x2+x3-xl-xr;
    int yl=min({y1,y2,y3});
    int yr=max({y1,y2,y3});
    int ym=y1+y2+y3-yl-yr;
    vector<pair<pair<int,int>,pair<int,int>>> ans;
    if(xl!=xr) ans.push_back({{xl,ym},{xr,ym}});
    if(y1!=ym) ans.push_back({{x1,y1},{x1,ym}});
    if(y2!=ym) ans.push_back({{x2,y2},{x2,ym}});
    if(y3!=ym) ans.push_back({{x3,y3},{x3,ym}});
    cout<<ans.size()<<"\n";
    for(auto[p,q]:ans)
    {
        cout<<p.first<<" "<<p.second<<" "<<q.first<<" "<<q.second<<"\n";
    }
}