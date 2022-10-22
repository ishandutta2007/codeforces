#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
pair<pair<int,int> ,int> a[300009];
int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].first.first>>a[i].first.second;
        a[i].second=i;
        a[i].first.second*=-1;
    }
    sort(a,a+n);
    int mx=0,u;
    for(int i=0;i<n;i++)
    {
        if(-a[i].first.second<=mx){cout<<a[i].second+1<<" "<<u+1;return 0;}
       u=a[i].second;
       mx=-a[i].first.second;
    }
    cout<<-1<<" "<<-1;
    return 0;
}