#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
int n;
pair<int,int>a[100009];
int coun[100009],pay[100009],tobe[100009];
int how[209];
int lesss(int num)
{int ans=0,u=0;
int i=1;
while(u<num)
{
int g =min(how[i],num-u);
u+=g;
ans+=i*g;
i++;

}

return ans;

}
int main()
{
scanf("%d",&n);
for(int i=0;i<n;i++)
scanf("%d",&a[i].first);
for(int i=0;i<n;i++)
{
scanf("%d",&a[i].second);
coun[a[i].first]++;
pay[a[i].first]+=a[i].second;


}
for(int i=100000;i>0;i--)
tobe[i]=tobe[i+1]+pay[i+1];
sort(a,a+n);
how[a[0].second]++;
int res=tobe[a[0].first];
for(int i=1;i<n;i++)
{

if(a[i].first==a[i-1].first){how[a[i].second]++;continue;}
int d=max(0,i-coun[a[i].first]+1);
tobe[a[i].first]+=lesss(d);
res=min(res,tobe[a[i].first]);
how[a[i].second]++;
}
printf("%d",res);
return 0;}