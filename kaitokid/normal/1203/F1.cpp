#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,x,y,sum,r;
multiset<pair<int,int> >ml1,ml2;
int main()
{
ios::sync_with_stdio(0);
cin>>n>>r;
sum=r;
for(int i=0;i<n;i++)
{
cin>>x>>y;
if(y>=0)ml1.insert(make_pair(x,y));

if(y<0)ml2.insert(make_pair(x+y,-1*y));
sum+=y;

}
if(sum<0){cout<<"NO\n";return 0;}
multiset<pair<int,int> > :: iterator it,it2,it3;
while(!ml2.empty())
{
it=ml2.lower_bound(make_pair(sum+1,0));
if(it==ml2.begin()){cout<<"NO\n";return 0;}
int mx=(*it).second;
it3=it;
it=ml2.begin();
it2=it;
while(it!=it3)
{
if((*it).second>mx){it2=it;mx=(*it).second;}
it++;


}
sum+=mx;
ml2.erase(it2);

}

while(!ml1.empty())
{
if((*ml1.begin()).first>r){cout<<"NO\n";return 0;}
r+=(*ml1.begin()).second;
ml1.erase(ml1.begin());


}
cout<<"YES\n";
return 0;}