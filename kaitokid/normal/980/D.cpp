#include <bits/stdc++.h>

using namespace std;
typedef long long ll;



int a[5004],ans[5004];
bool tr[5008];
map<int,int>mp;
bool pr[10009];
set<int>st;
int main()
{
    ios::sync_with_stdio(0);
cin.tie(0);
for(int i=2;i<100;i++)
{
    if(pr[i]==false)continue;
    for(int j=i*i;j<=10000;j+=i)pr[j]=true;
}
vector<int> v;
for(int i=2;i<10000;i++)if(!pr[i])v.push_back(i*i);
int n;
cin>>n;
int h=1;
for(int i=1;i<=n;i++)
{
    cin>>a[i];
    for(int j=0;j<v.size();j++)while((a[i]!=0)&&a[i]%v[j]==0)a[i]/=v[j];
  if(a[i]==0)continue;

    if((mp[a[i]])==0){mp[(a[i])]=h;a[i]=h; h++;}
    else a[i]=mp[a[i]];

}


for(int i=1;i<=n;i++)
{
    memset(tr,0,sizeof tr);
    int res=0;
    for(int j=i;j<=n;j++){if((a[j]!=0)&&(!tr[a[j]])){res++;tr[a[j]]++;}ans[max(1,res)]++;}
}

for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    return 0;
}