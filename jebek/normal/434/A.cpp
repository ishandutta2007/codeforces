#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

long long n,m,a[200000],ans1,ans,MAX,k;
vector<long long>v[200000];

int main()
{
    cin>>m>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(i && a[i]!=a[i-1])
        {
            ans+=abs(a[i]-a[i-1]);
            v[a[i]].push_back(a[i-1]);
            v[a[i-1]].push_back(a[i]);
        }
    }
    for(int i=1;i<=m;i++)
        if(v[i].size())
        {
            sort(v[i].begin(),v[i].end());
            ans1=0;
            for(int j=0;j<v[i].size();j++)
                ans1+=abs(v[i][j]-i);
            k=v[i][v[i].size()/2];
            for(int j=0;j<v[i].size();j++)
                ans1-=abs(v[i][j]-k);
            MAX=max(MAX,ans1);
        }
    cout<<ans-MAX<<endl;
}