#include <bits/stdc++.h>

/*Ordered Set starts*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define T int
#define ordered_set tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>

#define ll long long
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii >
#define eb emplace_back
#define sz(a) int((a).size())
#define sd(t) scanf("%d",&(t))


vii v,h,pts;
map<int,vii> mp1,mp2,mp3,mp4;
map<pii, int> myp;
int main()
{
    int n;
    sd(n);
    int x1,y1,x2,y2;
    for(int i = 0;i<n;i++)
    {
        sd(x1),sd(y1),sd(x2),sd(y2);
        if(y1 == y2)
        {   
            if(x1>x2)
                swap(x1,x2);
            mp1[y1].eb(mp(x1,x2));
        }
        else
        {
            if(y1>y2)
                swap(y1,y2);
            mp2[x1].eb(mp(y1,y2));
        }
    }
    vector<pair<int,pii > > pos;
    ll ret = 0;
    for(auto y: mp1){
        vii vec = y.S;
        sort(vec.begin(),vec.end());
        vii vec1;
        pii pr = mp(vec[0].F,vec[0].S);
        for(int i = 1;i<vec.size();i++)
        {
            int st = vec[i].F,en = vec[i].S;
            if(st > pr.S)
            {
                ret += pr.S-pr.F+1;
                vec1.eb(pr);
                pos.eb(mp(pr.F,mp(1,y.F)));
                pos.eb(mp(pr.S+1,mp(0,y.F)));
                pr = vec[i];
            }
            else
            {
                pr.S = max(pr.S,en);
            }
        }
        vec1.eb(pr);
        ret+=pr.S-pr.F+1;
        pos.eb(mp(pr.F,mp(1,y.F)));
        pos.eb(mp(pr.S+1,mp(0,y.F)));
    }
    for(auto x:mp2){
        vii vec = x.S;
        sort(vec.begin(),vec.end());
        vii vec1;
        pii pr = mp(vec[0].F,vec[0].S);
        for(int i = 1;i<vec.size();i++)
        {
            int st = vec[i].F,en = vec[i].S;
            if(st > pr.S)
            {
                ret+=pr.S-pr.F+1;
                vec1.eb(pr);
                pos.eb(mp(x.F,mp(2,pr.F)));
                myp[mp(x.F,pr.F)] = pr.S;
                pr = vec[i];
            }
            else
            {
                pr.S = max(pr.S,en);
            }
        }
        vec1.eb(pr);
        pos.eb(mp(x.F,mp(2,pr.F)));
        ret+=pr.S-pr.F+1;
        myp[mp(x.F,pr.F)] = pr.S;
    }
    sort(pos.begin(),pos.end());
    // find intersections
    ordered_set ys;
    for(int i = 0;i<pos.size();i++)
    {
        int a = pos[i].F,b = pos[i].S.F,c = pos[i].S.S;
        if(b == 1)
            ys.insert(c);
        if(b == 0)
            ys.erase(c);
        if(b == 2)
        {
            int h1 = c,h2 = myp[mp(a,c)];
            ret -= (ys.order_of_key(h2+1)-ys.order_of_key(h1));
        }
    }
    cout<<ret;
}