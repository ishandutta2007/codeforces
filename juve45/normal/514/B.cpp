#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
#define line pair<int, int>

map <line, int> m;

int Ox, Oy, n, a, b, x, y;

int main()
{
cin>>n;

    cin>>a>>b;
    int k=0;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;

        x-=a;
        y-=b;
        if(x==0)
        {
            Ox++;
        continue;
        }
        if(y==0)
            {
            Oy++;
        continue;
        }
        line l;
        int g=__gcd(x, y);
        x/=g;
        y/=g;
        l.x=x;
        l.y=y;

        if(m.find(l)==m.end())
            m[l]=k, k++;
    }

    cout<<k + (Ox!=0) + (Oy!=0);


    return 0;
}