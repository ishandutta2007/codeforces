#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
bool bl[300009];
int main()
{
ios::sync_with_stdio(0);
int t,n;
cin>>t;

    vector<pair<int,int> >ans;
while(t--)
{
    cin>>n;
    for(int i=1;i<=n;i++)bl[i]=false;
    ans.clear();
    int z=n;
    while(z>2){bl[z]=true;z=ceil(sqrt((z+0.0)));}
    for(int i=3;i<n;i++)
    if(!bl[i])ans.push_back({i,n});
    for(int i=n;i>2;i--)
    {
        if(bl[i])
        {
            ans.push_back({i,ceil(sqrt((i+0.0)))});
            ans.push_back({i,ceil(sqrt((i+0.0)))});
        }
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
}
    return 0;
}