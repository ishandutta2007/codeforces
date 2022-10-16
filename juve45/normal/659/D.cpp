#include <bits/stdc++.h>

using namespace std;

vector <pair <int, int> > v;

int area(pair<int, int> a, pair<int, int>b, pair<int, int>c)
{
    return a.first*b.second + b.first*c.second + a.second*c.first - a.first*c.second - b.first*a.second - c.first*b.second;
}
int n, x, y;
int main()
{
cin>>n;
int ans=0;
for(int i=0;i<=n;i++)
{
    cin>>x>>y;
    v.push_back({x, y});
}
v.push_back(v[1]);
for(int i=0;i<n;i++)
{
    if(area(v[i], v[i+1], v[i+2]) > 0) ans++;
}
cout<<ans<<'\n';
    return 0;
}