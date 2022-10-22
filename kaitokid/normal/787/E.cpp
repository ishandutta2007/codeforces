#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int bit[100009],n;
int cal(int x)
{
    int res=0;
    while(x>0){res+=bit[x];x-=(x&(-x));}
    return res;
}
void add(int x,int val)
{
    while(x<=n){bit[x]+=val;x+=(x&(-x));}
}
int fin(int x)
{
    int res=0;
    for(int i=18;i>=0;i--)
    {
        if((res|(1<<i))>n)continue;
        if(bit[res|(1<<i)]<x){res|=(1<<i);x-=bit[res];}
    }
    return res+1;
}
int ans[100009];
int a[100009];
int nx[100009],lst[100009];
vector<int>v[100009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
       cin>>a[i];
    for(int i=n;i>=1;i--)
    {
        if(lst[a[i]])nx[i]=lst[a[i]];
        lst[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        v[1].push_back(i);
        if(lst[i]!=0)add(lst[i],1);
    }
    for(int i=1;i<=n;i++)
     {
     for(int j=0;j<v[i].size();j++){
       v[fin(v[i][j]+1)].push_back(v[i][j]);ans[v[i][j]]++;}
     add(i,-1);
     if(nx[i])add(nx[i],1);
     }
     for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";

    return 0;
}