#include <bits/stdc++.h>

using namespace std;
bool cat[100300];
vector<int> a[100300];
int ans=0,m;
void f(int x,int parent,int y)
{
    if(a[x].empty()||a[x].size()==1)
    {//cout<<x<<" "<<y<<endl;
        ans++;
        return;
    }
    for(int i=0; i<a[x].size(); i++)
    {
        if(a[x][i]!=parent)
        {if((cat[a[x][i]])&&1+y>m){continue;}
            if((cat[a[x][i]])&&1+y<=m)
            {
                f(a[x][i],x,y+1);
            }
            if(!cat[a[x][i]])
            {
                f(a[x][i],x,0);
            }
        }


    }

}
int main()
{
    int n,x,y;
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        cin>> cat[i+1];
    }
    for(int i=0; i<n-1; i++)
    {
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    a[1].push_back(-1);
    f(1,-1,cat[1]);
    cout<<ans;

    return 0;
}