#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
double ans;
vector<int>v[100008];
void go(int x,int pr,int l,double p)
{
    if(v[x].size()==1){ans+=l*p;return;}
    p*=(1.0/(v[x].size()-1.0));
    for(int i=0;i<v[x].size();i++)
        if(v[x][i]!=pr)go(v[x][i],x,l+1,p);
}

int main()
{
    ios::sync_with_stdio(0);
cin>>n;
int x,y;
for(int i=0;i<n-1;i++)
{
    cin>>x>>y;
    v[x].push_back(y);
    v[y].push_back(x);
}
v[1].push_back(0);
go(1,0,0,1.0);
cout<<fixed<<setprecision(8)<<ans;
    return 0;
}