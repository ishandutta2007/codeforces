#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>v[100009];
int a[11][200009];
int c[11],n;
vector<int>ans;
int cal(vector<int>& g)
{
    int res=0;
    for(int i=0;i<n;i++)res+=a[i][g[i]];
    return res;
}
int main(){
scanf("%d",&n);
for(int i=0;i<n;i++)
{
    scanf("%d",&c[i]);
    for(int j=1;j<=c[i];j++)scanf("%d",&a[i][j]);
}
int m,x;
scanf("%d",&m);
for(int i=0;i<m;i++)
    for(int j=0;j<n;j++){scanf("%d",&x);v[i].push_back(x);}
sort(v,v+m);

vector<int>tmp;
for(int i=0;i<n;i++)tmp.push_back(c[i]);
if(*lower_bound(v,v+m,tmp)!=tmp ){

for(int i=0;i<n;i++)printf("%d ",tmp[i]);

return 0;}
int rs=0;
for(int i=0;i<m;i++)
{
    tmp=v[i];
    int sum=cal(v[i]);
    for(int j=0;j<n;j++){if(tmp[j]==1)continue;
    sum-=a[j][tmp[j]];
    tmp[j]--;
    sum+=a[j][tmp[j]];

    if(sum>rs &&(*lower_bound(v,v+m,tmp)!=tmp) ){
    rs=sum;ans=tmp;}
     sum-=a[j][tmp[j]];
    tmp[j]++;
    sum+=a[j][tmp[j]];

     }

}
for(int i=0;i<n;i++)printf("%d ",ans[i]);

  return 0;
}