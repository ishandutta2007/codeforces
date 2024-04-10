#include <bits/stdc++.h> 
using namespace std; 
typedef long long ll;
int n,a[30];
vector<int>v[30];
string x,y;
void go(int  q,int w)
{

int s=a[q];
while(s!=a[s])s=a[s];
int f=a[w];
while(f!=a[f])f=a[f];
a[s]=f;

if(s==f)return ;
//cout<<endl<<v[f].size()<<endl;
for(int u=0;u<v[s].size();u++){//cout<<v[s][u]<<" ";
v[f].push_back(v[s][u]);}
//cout<<endl<<v[f].size()<<endl;
v[s].clear();

}
int main() 
{ 
ios::sync_with_stdio(0);

for(int i=1;i<=26;i++)
{
a[i]=i;
v[i].push_back(i);

}
cin>>n;

cin>>x>>y;
for(int i=0;i<n;i++)
{


int p1=(int)x[i];
int p2=(int)y[i];
p1-=96;
p2-=96;


go(p1,p2);


}
 
int ans=0;
for(int i=1;i<=26;i++)
{
if(v[i].size()<2)continue;

ans+=v[i].size()-1;


}
cout<<ans<<endl;
for(int i=1;i<=26;i++)
{
for(int j=1;j<v[i].size();j++)
cout<<char(v[i][j-1]+int('a')-1)<<" "<<char(int('a')+v[i][j]-1)<<endl;


}
return 0 ;}