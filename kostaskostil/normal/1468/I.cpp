#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

#define div weoigneribe
int div(int p,int q)
{
    int res=p/q;
    if ((res*q<p and q>0)
        or(res*q>p and q<0))
        res++;
    return res;
}

void cut(int&l,int&r,int p,int q)
{
    if(p>q)
        swap(p,q);
    l=max(l,p);
    r=min(r,q);
}

int sign(int val)
{
    return val<0?-1:1;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,x1,y1,x2,y2;
    cin>>n>>x1>>y1>>x2>>y2;

    int area=abs(x1*y2-y1*x2);
    if(area!=n)
        cout<<"NO",exit(0);

    set<pii> s;

    if(x1==0&&y2==0)
    {
        for(int x=0;x!=x2;x+=sign(x2))
            for(int y=0;y!=y1;y+=sign(y1))
                s.insert({x,y});
    }
    else if(x2==0&&y1==0)
    {
        for(int x=0;x!=x1;x+=sign(x1))
            for(int y=0;y!=y2;y+=sign(y2))
                s.insert({x,y});
    }
    else
    {
        bool sw=x1==0||x2==0;
        if(sw)
            swap(x1,y1),
            swap(x2,y2);
        for(int x=-abs(x1)-abs(x2); x<=abs(x1)+abs(x2);x++)
        {
            int l=-1e9,r=1e9;
            cut(l,r,div(x*y1,x1),div(x*y1-x2*y1+x1*y2,x1));
            cut(l,r,div(x*y2,x2),div(x*y2-x1*y2+x2*y1,x2));
            for(int y=l;y<r;y++)
                s.insert(sw?pair{y,x}:pair{x,y});
        }
        if(sw)
            swap(x1,y1),
            swap(x2,y2);
    }

    s.insert({0,0});
    s.erase({x1,y1});
    s.erase({x2,y2});
    s.erase({x1+x2,y1+y2});

    cout<<"YES\n";
    for(auto[x,y]:s)
        cout<<x<<" "<<y<<"\n";
}