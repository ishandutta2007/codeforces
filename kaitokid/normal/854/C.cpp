#include <bits/stdc++.h>
using namespace std;
set<pair<long long,long long> >a;
long long ans[400000];
long long res;
int main (){
ios::sync_with_stdio(0);
int n,k;
cin>>n>>k;
long long x;
for(int i=1;i<=k;i++)
{cin>>x;
a.insert(make_pair(x,i));}
for(int i=k+1;i<=n;i++)
{
cin>>x;
a.insert(make_pair(x,i));
set <pair<long long,long long> >::iterator it=a.end();
it--;
pair <long long,long long> t=*it;
ans[t.second]=i;
res+=(i-t.second)*t.first;
a.erase(it);


}
int i=n+1;
while(!a.empty())
{set <pair<long long,long long> >::iterator it=a.end();
it--;
pair <long long,long long> t=*it;
ans[t.second]=i;
res+=(i-t.second)*t.first;
i++;
a.erase(it);
}
cout<<res<<endl;
for(int j=1;j<=n;j++)
cout<<ans[j]<<" ";
return 0;}