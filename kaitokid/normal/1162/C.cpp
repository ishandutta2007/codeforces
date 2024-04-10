#include <bits/stdc++.h>

using namespace std;
int n,a[100009],k;
bool vis[100009];
set<pair<int,int> >no;
int main()
{
    ios::sync_with_stdio(0);
    cin>>n>>k;
    for(int i=0;i<k;i++)
    cin>>a[i];
    for(int i=k-1;i>=0;i--)
    {
        vis[a[i]]=true;
        no.insert(make_pair(a[i],a[i]));
        if(vis[a[i]+1])no.insert(make_pair(a[i],a[i]+1));
 if(vis[a[i]-1])no.insert(make_pair(a[i],a[i]-1));
    }

    cout<<3*n-2-no.size();
    return 0;
}