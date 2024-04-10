#include<bits/stdc++.h>
using namespace std;
int n,c[200009],a[200009];
bool vs[200009],vs2[200009];
int ans=0,res;
void fuck(int i,int x)
{
res=min(c[i],res);
if(i==x){ans+=res;return ;}
fuck(a[i],x);


}
void go(int x)
{
if(vs2[x]){res=99999;fuck(a[x],x);return ;}
if(vs[x])return ;
vs[x]++;
vs2[x]++;
go(a[x]);


}

int main()
{
ios::sync_with_stdio(0);
cin>>n;
for(int i=1;i<=n;i++)cin>>c[i];
for(int i=1;i<=n;i++)cin>>a[i];
for(int i=1;i<=n;i++)
{
if(vs[i])continue;
memset(vs2,0,sizeof vs2);
go(i);

}
cout<<ans;
}