#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
ll v[100009],mark[100009],n,x,y,mxinc[100009],mxdec[100009];
vector<int> g[100009];
int dfs(int x){
 ll m1=0,m2=0;mark[x]=1;
 f(i,0,g[x].size()){
  if(mark[g[x][i]]==0){
   dfs(g[x][i]);
   m1=max(m1,mxinc[g[x][i]]);
   m2=max(m2,mxdec[g[x][i]]);}}
 if(v[x]-(m1-m2)>0) m1+=v[x]-(m1-m2);
 else m2+=abs(v[x]-(m1-m2));
 mxinc[x]=m1;
 mxdec[x]=m2;
}
int main(){
 cin>>n;
 f(i,0,n-1){
  cin>>x>>y;
  g[x].push_back(y);g[y].push_back(x);}
 f(i,1,n+1) cin>>v[i];
 dfs(1);
 cout<<mxinc[1]+mxdec[1];
}