#include <iostream>
#include<vector>

using namespace std;

bool mark[300],mark1[300];
int n,t,a[300],m[300][300];
vector<int>ans;

void dfs(int v)
{
    ans.push_back(v);
    mark[v]=true;
    for(int i=1;i<=200;i++)
        if(m[v][i]>1 && !mark[i])
            dfs(i);
}

int main()
{
    cin>>n;
    for(int i=0;i<n*(n-1)/2;i++)
    {
        cin>>t;
        for(int j=0;j<t;j++)
        {
            cin>>a[j];
            mark1[a[j]]=true;
            for(int u=0;u<j;u++)
            {
                m[a[j]][a[u]]++;
                m[a[u]][a[j]]++;
            }
        }
    }
    if(n==2)
    {
        cout<<1<<" "<<a[0]<<endl<<t-1<<" ";
        for(int i=1;i<t;i++)
            cout<<a[i]<<" ";
        cout<<endl;
        return 0;
    }
    for(int i=1;i<=200;i++)
        if(mark1[i] && !mark[i])
        {
            dfs(i);
            cout<<ans.size()<<" ";
            for(int i=0;i<ans.size();i++)
                cout<<ans[i]<<" ";
            cout<<endl;
            ans.clear();
        }
}