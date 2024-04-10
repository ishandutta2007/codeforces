#include <bits/stdc++.h>

using namespace std;

long long int n,a,b,base,x,y,gain,res,ma,i,g,sg[200005],mi;

int main()
{
    ios_base::sync_with_stdio(false);
    priority_queue<pair<long long int,pair<long long int,long long int>>> p;
    cin>>n>>a>>b;
    for (int i=1;i<=n;i++)
        {
            cin>>x>>y, base+=y;
            p.push({x-y, {x, y}});
        }
    while (!p.empty())
    {
        i++;
        auto t=p.top();
        p.pop();
        x=t.second.first;
        y=t.second.second;
        if (t.first>0&&i<=b)
            {
                gain+=t.first,g++;
                sg[i]=x*(1<<a)-x;
            }
        else
        {
            sg[i]=x*(1<<a)-mi-y;
        }
        if (i==b&&g==b)
            mi=t.first;
    }
    if(b)
        for (int i=1;i<=n;i++)
            if (sg[i]>ma)
                ma=sg[i];
    base+=gain;
    base+=ma;
    cout<<base;
    return 0;
}