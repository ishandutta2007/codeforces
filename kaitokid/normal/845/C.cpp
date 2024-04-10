#include <bits/stdc++.h>
using namespace std ;
vector<pair<pair<long long,long long>,bool> >a ;
int main (){
ios::sync_with_stdio(0);
long long n,x,y;
cin>>n;
for(int i=0;i<n;i++)
{cin>>x>>y;
a.push_back(make_pair(make_pair(x,y),0));


}
if(n<3){cout<<"YES";return 0;}
sort(a.begin(),a.end());
long long l = a[0].first.second;
a[0].second=1;
for(int i=1;i<n;i++)
{if (a[i].first.first<=l)continue;
a[i].second=1;
l=a[i].first.second; }
l =-1;
for(int i=1;i<n;i++)
{if(a[i].second)continue;
if(a[i].first.first<=l){cout<<"NO";return 0;}
l=a[i].first.second;}
cout<<"YES";
return 0;
}