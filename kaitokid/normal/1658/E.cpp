#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
int a[2009][2009];
bool ans[2009][2009];
bool bl(pair<int,int> x,pair<int,int> y)
{
    return a[x.first][x.second]>a[y.first][y.second];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    int x=2000,y=2000;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {
        cin>>a[i][j];
        if(a[i][j]>a[x][y]){x=i,y=j;}
    }
    vector<pair<int,int> >v;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        if(abs(x-i)+abs(y-j)>k){ans[i][j]=false;}
        else v.push_back({i,j});
        sort(v.begin(),v.end(),bl);

        int mn[4]={40000,40000,40000,40000};
        // x+y , x-y, -x+y ,-x-y
        for(int i=0;i<v.size();i++)
        {
            int h=v[i].first,z=v[i].second;
            int r=max(max(h+z-mn[0],h-z-mn[1]),max(-h+z-mn[2],-h-z-mn[3]));
            if(r>k)continue;
            ans[h][z]=true;
            mn[0]=min(mn[0],h+z);
            mn[1]=min(mn[1],h-z);
            mn[2]=min(mn[2],-h+z);
            mn[3]=min(mn[3],-h-z);

        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)if(ans[i][j])cout<<"M";
            else cout<<"G";
            cout<<endl;
        }

    return 0;
}