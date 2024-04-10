#include <bits/stdc++.h>

#define x first
#define y second
using namespace std;

typedef pair<int, pair<int, int> > piii;

priority_queue <piii> p;

int n, ans[1000], x;

int main()
{

    cin>>n;
    for(int i=2;i<=2*n;i++)
    {
        for(int j=1;j<i;j++)
        {
            cin>>x;
            p.push({x,{i, j}});
        }
    }
    int nr=0;
    while(!p.empty() && nr!=n)
    {

        piii a=p.top();
        p.pop();
        if(ans[a.y.x]==0 && ans[a.y.y]==0)
        {
        ans[a.y.x]=a.y.y;
        ans[a.y.y]=a.y.x;
        nr++;
        }

    }

    for(int i=1;i<=2*n;i++)
    {
        cout<<ans[i]<<' ';
    }

    return 0;

}