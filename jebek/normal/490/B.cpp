#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n,a,b,p,f[1100000],ans[500000];
vector<int>v;
bool mark[1100000];

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        f[a]=b;
        v.push_back(a);
        mark[b]=true;
    }p=0;
    for(int i=1;i<n;i+=2)
    {
        p=f[p];
        ans[i]=p;
    }
    for(int i=0;i<v.size();i++)
        if(v[i]!=0 && !mark[v[i]])
            p=v[i];
    for(int i=0;i<n;i+=2)
    {
        ans[i]=p;
        p=f[p];
    }
    for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}