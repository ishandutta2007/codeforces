#include<bits/stdc++.h>
using namespace std;
int cost[28][28][509],dp[28][28][509];
int n,m;

int how[28][2];
pair<int,int> pr[27][27][509];
int see (int wh,int x,int y)
{
int res=10000000;
for(int i=0;i<26;i++){
if(i==x)continue;
for(int j=0;j<26;j++) 
{
if(j==y||i==j)continue;
if(dp[i][j][wh]<res){pr[x][y][wh+1]=make_pair(i,j);}
res=min(res,dp[i][j][wh]);


}

}

return res;

}
int main()
{
ios::sync_with_stdio(0);
cin>>n>>m;
char w;
for(int i=0;i<n;i++)
{
memset(how,0,sizeof how);
for(int j=0;j<m;j++)
{
cin>>w;
how[w-'a'][j%2]++;

}
for(int j=0;j<26;j++)
for(int k=0;k<26;k++){
if(j==k)continue;
cost[j][k][i]=m-how[j][0]-how[k][1];
//cout<<cost[j][k][i];
}
//cout<<endl;


}
for(int i=0;i<26;i++)
for(int j=0;j<26;j++)dp[i][j][0]=cost[i][j][0];
for(int k=1;k<n;k++)
{
for(int i=0;i<26;i++)

for(int j=0;j<26;j++)dp[i][j][k]=see(k-1,i,j)+cost[i][j][k];





}
int x,y;
int ans=10000000;
for(int i=0;i<26;i++)
for(int j=0;j<26;j++)
{
if(i==j)continue;
if(dp[i][j][n-1]<ans){x=i;y=j;}
ans=min(ans,dp[i][j][n-1]);
}
cout<<ans;
int l=n-1;
vector<pair<int,int> > st;
while(l>=0)
{
st.push_back(make_pair(x,y));
int x2=pr[x][y][l].first;
int y2=pr[x][y][l].second;
x=x2;
y=y2;
l--;


}
for(int i=n-1;i>=0;i--)
{
cout<<endl;
char t[2];
t[0]=char('a'+st[i].first);
t[1]=char('a'+st[i].second);
for(int j=0;j<m;j++)cout<<t[j%2];

}




}