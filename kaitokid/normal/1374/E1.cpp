#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,k,x,y,z;
ll ans;
vector<int>a[2][2];
int id[2][2];
int main()
{
ios::sync_with_stdio(0);
cin>>n>>k;
for(int i=0;i<n;i++)
{

    cin>>x>>y>>z;
    a[y][z].push_back(x);
}
for(int i=0;i<2;i++)
    for(int j=0;j<2;j++){sort(a[i][j].begin(),a[i][j].end());a[i][j].push_back(1000000);}
int u=0,v=0;

while(u<k||v<k)
{
    if(u<k&&v<k)
    {
        id[1][1];

        ll ans1=a[1][1][id[1][1]];
        ll ans2=a[1][0][id[1][0]]+a[0][1][id[0][1]];
        if(min(ans1,ans2)>100000){cout<<-1;return 0;}
        if(ans1<ans2){ans+=ans1;id[1][1]++;}
        else {ans+=ans2;id[1][0]++;id[0][1]++;}
        u++;
        v++;
        continue;
    }
    int l=(u<k),r=(v<k);
    ll ans2=a[l][r][id[l][r]];
    ll ans1=a[1][1][id[1][1]];
    if(min(ans1,ans2)>100000){cout<<-1;return 0;}
        if(ans1<ans2){ans+=ans1;id[1][1]++;}
        else {ans+=ans2;id[l][r]++;}
        u++;
        v++;
}
cout<<ans;
   return 0;
}