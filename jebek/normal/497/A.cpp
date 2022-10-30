#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n,m,ans;
char c[200][200];
bool mark[200],mark1[200];
vector<int>v;

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>c[i][j];
    for(int j=0;j<m;j++)
    {
        v.clear();
        for(int i=0;i<n-1;i++)
        {
            if(c[i][j]<c[i+1][j])
                v.push_back(i);
            else if(!mark[i] && c[i][j]>c[i+1][j])
                mark1[j]=true;
        }
        if(!mark1[j])
            for(int i=0;i<v.size();i++)
                mark[v[i]]=true;
    }
    for(int i=0;i<m;i++)
        if(mark1[i])
            ans++;
    cout<<ans<<endl;
}