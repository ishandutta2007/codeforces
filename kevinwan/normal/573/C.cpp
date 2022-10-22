#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(423978);
typedef long long ll;
typedef pair<ll,ll>pll;
const int mn=5e5+10;
set<int>g[mn];
int ori[mn];
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
   int n;
   cin>>n;
   for(int i=0;i<n-1;i++){
       int a,b;
       cin>>a>>b;
       g[a].insert(b);
       g[b].insert(a);
   }
   stack<int>s;
   for(int i=1;i<=n;i++){
       ori[i]=g[i].size();
       if(ori[i]==1)s.push(i);
   }
   while(s.size()){
       int x=s.top();
       s.pop();
       int y=*g[x].begin();
       g[x].erase(y);
       g[y].erase(x);
       if(g[y].size()==1&&ori[y]<=2)s.push(y);
   }
   for(int i=1;i<=n;i++)if(g[i].size()==1&&ori[i]==3){
       int j=*g[i].begin();
       g[i].erase(j);
       g[j].erase(i);
   }
   for(int i=1;i<=n;i++)if(g[i].size()>=3){
       printf("No");
       return 0;
   }
   printf("Yes");
}