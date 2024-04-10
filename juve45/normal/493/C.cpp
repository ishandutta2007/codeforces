#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define dmax 200005
#define pb push_back
#define mp make_pair
#define x first
#define y second
using namespace std;
int n, a[dmax], b[dmax], m, va, vb, x, difm, ssa, ssb;
vector <pair<int, int> >v;
int main()
{
    //freopen("in.txt", "r", stdin);
    cin>>n;
    int sa=0, sb=0;

    for(int i=1; i<=n; i++)
    {
        cin>>x;
        v.pb(mp(x, 1));
        sa+=3;
    }

    cin>>m;
    for(int i=1; i<=m; i++)
    {
        cin>>x;
        v.pb(mp(x, -1));
        sb+=3;
    }
    sort(v.begin(), v.end());

    difm=sa-sb;
    ssa=sa;
    ssb=sb;


    for(int i=0; i<v.size(); i++)
    {
        while(v[i].x==v[i+1].x && i+1<v.size())
        {
            if(v[i].y==1)
                sa--;
            if(v[i].y==-1)
                sb--;
            i++;
        }
        if(v[i].y==1)
            sa--;
        if(v[i].y==-1)
            sb--;
        if(sa-sb>difm)
        {
            difm=sa-sb;
            ssa=sa;
            ssb=sb;
        }

    }
    cout<<ssa<<":"<<ssb<<'\n';

    return 0;
}