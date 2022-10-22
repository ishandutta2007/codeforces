#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD= 1e9 + 7;
bool g[55][55];
ll ans,t1[6],t2[6];
int d1,d2,f1,f2;

int main()
{
ios::sync_with_stdio(0);
string s;
ll n,m;
cin>>n>>m;
char x;

for(int i=0;i<n;i++)
{
for(int j=0;j<m;j++)
{
cin>>x;
if(x=='#')g[i][j]++;
if(x=='S'){d1=i;d2=j;}
if(x=='E'){f1=i;f2=j;}



}}

cin>>s;



/*t1[0]=1;
t2[0]=0;
t1[1]=-1;
t2[1]=0;
t1[2]=0;
t2[2]=1;
t1[3]=-1;
t2[3]=0;
for(int p1=-1;p1<2;p1++)
{
for(int p2=-1;p2<2;p2++)
{
if(p1!=0&&p2!=0)continue;
for(int p3=-1;p3<2;p3++)
{
for(int p4=-1;p4<2;p4++)
{
if(p1!=0&&p2!=0)continue;
if(*/



for(t1[0]=-1;t1[0]<2;t1[0]++)
{
for(t2[0]=-1;t2[0]<2;t2[0]++)
{
for(t1[1]=-1;t1[1]<2;t1[1]++)
{
for(t2[1]=-1;t2[1]<2;t2[1]++)
{
for(t1[2]=-1;t1[2]<2;t1[2]++)
{
for(t2[2]=-1;t2[2]<2;t2[2]++)
{
for(t1[3]=-1;t1[3]<2;t1[3]++)
{
for(t2[3]=-1;t2[3]<2;t2[3]++)
{
int bb=0;
for(int r1=0;r1<4;r1++)
{
if(t1[r1]==0&&t2[r1]==0){bb++;continue;}
if(t1[r1]!=0&&t2[r1]!=0){bb++;continue;}
for(int r2=0;r2<4;r2++)if(r1!=r2&&t1[r1]==t1[r2]&&t2[r1]==t2[r2]){bb++;continue;}
}
if(bb>0)continue;

int x1=d1,y1=d2;

for(int i=0;i<s.size();i++)
{
int h=s[i]-'0';

x1+=t1[h];
y1+=t2[h];
if(x1==f1&&y1==f2){ans++;break;}
if(x1<0||x1>=n||y1<0||y1>=m||g[x1][y1])break;



}


}}}}}}}}
cout<<ans;
return 0;}