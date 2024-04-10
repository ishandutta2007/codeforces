#include<bits/stdc++.h>
using namespace std;
map <double,vector<pair<int,int> > > mp;
map<double,bool>used;
int a[1004];
set<double> sr;
int main()
{
int n;
cin>>n;
for(int i=1;i<=n;i++)
cin>>a[i];
//if(n<=4){cout<<"Yes";return 0;}
for(int i=1;i<n;i++)
{used.clear();
for(int j=i+1;j<=n;j++)
{double u = (j-i-0.0)/(a[j]-a[i]+0.0);
if(!used[u])mp[u].push_back(make_pair(i,j));
used[u]=true;
sr.insert(u);}}
for(set<double>::iterator it =sr.begin();it!=sr.end();it++)
{
if(mp[*it].size()==n-2){cout<<"Yes";return 0;}


}


cout<<"No";
return 0;
}