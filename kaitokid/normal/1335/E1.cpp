#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<int>v[205];
int a[200009];
int go(int x,int y)
{

    int ans=0;
    if(x>y)return 0;
    for(int i=1;i<=200;i++)
    {
        int u=(lower_bound(v[i].begin(),v[i].end(),y+1)-v[i].begin());
        int h=(lower_bound(v[i].begin(),v[i].end(),x)-v[i].begin());
        ans=max(ans,u-h);
    }
   // cout<<x<<" "<<y<<" "<<ans<<endl;
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
int t,n;

cin>>t;
while(t--)
{
cin>>n;
for(int i=0;i<n;i++)
{
    cin>>a[i];
    v[a[i]].push_back(i);
}

int ans=0;
for(int q=1;q<=200;q++)
{

    int i=0,j=v[q].size();
ans=max(ans,j);
    j--;
    while(j>i)
    {


        ans=max(ans,2*(i+1)+go(v[q][i]+1,v[q][j]-1));

        i++;
        j--;
    }

}
for(int i=1;i<=200;i++)v[i].clear();
cout<<ans<<endl;
}
    return 0;
}