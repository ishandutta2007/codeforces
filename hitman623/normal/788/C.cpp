#include <bits/stdc++.h>
#define pb push_back

using namespace std;

map < long ,vector < long > > ad;
map < long , long > visi,cnt;

long bfs()
{
    long n,i;
    list < long > q;
    q.pb(0);
    visi[0]=1;
    while(!q.empty())
    {
        n=q.front();
        q.pop_front();
        for(i=0;i<ad[n].size();++i)
        {
            if(visi[ad[n][i]] && ad[n][i]==0) return cnt[n]+1;
            else if(!visi[ad[n][i]])
            {
                visi[ad[n][i]]=1;
                q.pb(ad[n][i]);
                cnt[ad[n][i]]=cnt[n]+1;
            }
        }
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long n,k,a[1003]={0},i,x,j;
    vector < long > v;
    cin>>n>>k;
    for(i=0;i<k;++i)
    {
        cin>>x;
        if(a[x]==0)
        {
            a[x]=1;
            v.pb(x-n);
        }
    }
    for(i=-1000;i<1001;++i)
    {
        for(j=0;j<v.size();++j)
            ad[i].pb(i+v[j]);
    }
    cout<<(bfs());
    return 0;
}