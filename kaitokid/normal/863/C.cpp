#include <bits/stdc++.h>
using namespace std;
pair<long long ,pair<long long,long long> >wh[4][4];
long long pl1[4][4],pl2[4][4];
bool used [4][4];
int main()
{
 long long k,a,b;
cin>>k>>a>>b;
for(int i=1;i<4;i++)
{for(int j=1;j<4;j++)cin>>pl1[i][j];}
for(int i=1;i<4;i++)
{for(int j=1;j<4;j++)cin>>pl2[i][j];}
long long num=0;
long long c1=0,c2=0;
while(!used[a][b])
{
used[a][b]=true;

wh[a][b]=make_pair(num,make_pair(c1,c2));
//cout<<c1<<c2;
num++;

if(a==b+1||(a==1&&b==3))c1++;
else{if(a!=b)c2++;}
if(num==k){cout<<c1<<" "<<c2;return 0;}
long long g=a;
a=pl1[a][b];
b=pl2[g][b];

}
num-=wh[a][b].first;
long long r1=c1-wh[a][b].second.first;
long long  r2 =c2-wh[a][b].second.second;
k-=num+wh[a][b].first;

c1+=r1*(k/num);
c2+=r2*(k/num);
k=k%num;
long long  z=0;
//cout<<c1<<" "<<c2<<endl<<z<<endl;
while(z<k)
{
if(a==b+1||(a==1&&b==3))c1++;
else{if(a!=b)c2++;}
z++;
long long hh=a;
a=pl1[a][b];
b=pl2[hh][b];

}
cout<<c1<<" "<<c2;
return 0;}