#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

void solve()
{
    string s;
    cin>>s;
    set<pii> pos;
    int x=0,y=0;
    for(char c:s)
    {
        if(c=='L')
            x--;
        else if(c=='R')
            x++;
        else if(c=='D')
            y--;
        else if(c=='U')
            y++;
        pos.insert({x,y});
    }
    pos.erase({0,0});
    for(auto[x0,y0]:pos)
    {
        x=y=0;
        for(char c:s)
        {
            int x1=x,y1=y;
            if(c=='L')
                x--;
            else if(c=='R')
                x++;
            else if(c=='D')
                y--;
            else if(c=='U')
                y++;
            if(pair(x,y)==pair(x0,y0))
                tie(x,y)=pair(x1,y1);
        }
        if(x==0&&y==0)
        {
            cout<<x0<<" "<<y0<<"\n";
            return;
        }
    }
    cout<<"0 0\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
        solve();
}