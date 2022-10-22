#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
bool bl[1001];
vector<int>v;
int n,a[200009],ans;
map<int,int>mp[200009];
vector<int>d[200009];
void fuck(int x,int pr,int k)
{
int mx=0,mx2=0;
for(int i=0;i<d[x].size();i++)
{
if(d[x][i]==pr)continue;
int r=mp[d[x][i]][k];
int f=min(mx,r);
mx=max(mx,r);
mx2=max(mx2,f);


}
ans=max(ans,mx+mx2+1);
mp[x][k]=mx+1;

}

void go(int x,int pr)
{
for(int i=0;i<d[x].size();i++)
if(d[x][i]==pr)continue;
else go(d[x][i],x);
for(int i=0;i<v.size();i++)

{if(a[x]%v[i]!=0)continue;
fuck(x,pr,v[i]);
while(a[x]%v[i]==0)a[x]/=v[i];
}
if(a[x]>1)fuck(x,pr,a[x]);

}
int main()
{
ios::sync_with_stdio(0);
for(int i=2;i<1001;i++)
{if(bl[i])continue;
v.push_back(i);
for(int j=i*i;j<1001;j+=i)bl[j]=true;}
cin>>n;
for(int i=1;i<=n;i++)cin>>a[i];
int x,y;
for(int i=1;i<n;i++)
{
cin>>x>>y;
d[x].push_back(y);
d[y].push_back(x);
}
go(1,0);
cout<<ans;
return 0;
}