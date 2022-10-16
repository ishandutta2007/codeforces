#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

priority_queue <pair<int, int> > p;
int n, g, ans,k;
int main()
{
    cin>>n>>g;
    for(int i=1; i<=n; i++)
    {
        cin>>k;
        p.push({k%10, k});
    }
int ans=0;
    while(g!=0 && !p.empty())
    {
        int add;
        pair<int, int> a=p.top();
        p.pop();
        if(a.x!=0)
        {
            add=min(10-a.x, g);
            a.x+=add;
            a.x%=10;
            a.y+=add;

        }
        else
        {
            add=min(100-a.y, g);
            a.y+=add;
        }
        g-=add;
        if(a.y!=100)
            p.push(a);
            else ans+=10;
    }

while(!p.empty())
{
    pair<int, int> a=p.top();
    p.pop();
    ans+=a.y/10;
}
cout<<ans<<'\n';
    return 0;
}