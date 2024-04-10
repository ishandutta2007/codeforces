#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
int vis[200005];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        vis[a[i]]++;
        if(vis[a[i]]==3)
        {
            cout<<"NO"<<endl;return 0;
        }
    }
    vector<int>x,y;
    cout<<"YES"<<endl;
    for(int i=0;i<=200000;i++)
    {
        if(vis[i])
            x.push_back(i);
        if(vis[i]==2)
            y.push_back(i);
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    reverse(y.begin(),y.end());
    cout<<x.size()<<endl;
    for(int i=0;i<x.size();i++)
        cout<<x[i]<<' ';
    cout<<endl;
    cout<<y.size()<<endl;
    for(int i=0;i<y.size();i++)
        cout<<y[i]<<' ';
    cout<<endl;
}