#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n,a[300],ans,MAX=-200000,y;
unsigned int k;
vector<int>x,v;

int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            v.clear();x.clear();
            ans=0;
            for(int u=0;u<i;u++)
                v.push_back(a[u]);
            for(int u=i;u<=j;u++)
                x.push_back(a[u]);
            for(int u=j+1;u<n;u++)
                v.push_back(a[u]);
            sort(v.begin(),v.end());
            y=min(k,min(x.size(),v.size()));
            for(int u=0;u<y;u++)
                x.push_back(v[v.size()-1-u]);
            sort(x.begin(),x.end());
            for(int u=0;u<=j-i;u++)
                ans+=x[x.size()-1-u];
            MAX=max(ans,MAX);
        //    cout<<i<<" "<<j<<" "<<ans<<" "<<y<<endl;
        }
    }
    cout<<MAX<<endl;
}