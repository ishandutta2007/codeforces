#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<int,pair<int,int> > lst;
map<pair<int,int> ,vector<pair<int,int> > >v;
int sz[200009];
map<pair<int,int> ,int> cl;
void go(int x,int y,int c)
{
    cl[{x,y}]=c;
    if(c==1)c=2;
    else c=1;
    vector<pair<int,int> >h=v[{x,y}];
    for(int i=0;i<h.size();i++)
    {
        pair<int,int>g=h[i];
        if(cl[g]==0)go(g.first,g.second,c);
    }

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin>>m;
    int r=0;
    for(int i=1;i<=m;i++)
    {
        cin>>sz[i];
        for(int j=1;j<=sz[i];j++)
        {
            int x;
            cin>>x;
            pair<int,int>g=lst[x];
            if(g.first==0){lst[x]={i,j};r++;continue;}
            v[g].push_back({i,j});
            v[{i,j}].push_back(g);
            lst[x]={0,0};
            r--;
        }
        for(int j=1;j<sz[i];j+=2)
        {
            v[{i,j}].push_back({i,j+1});
            v[{i,j+1}].push_back({i,j});
        }
    }
    if(r>0){cout<<"NO"<<endl;return 0;}

    cout<<"YES"<<endl;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=sz[i];j++)
    {if(cl[{i,j}]==0)go(i,j,1);
    if(cl[{i,j}]==1)cout<<"L";
    else cout<<"R";
    }
    cout<<endl;
}
    return 0;
}