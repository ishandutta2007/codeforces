#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
ll w(ll fir,ll en,ll num)
{

while(en>=fir)
{
ll mid=(fir+en)/2;
if(mid*mid*mid==num)return mid;
if(mid*mid*mid>num)en=mid-1;
if(mid*mid*mid<num)fir=mid+1;





}

return -1;


}
int main()
{
ios::sync_with_stdio(0);
int n;
ll a,b;
scanf("%d",&n);
while(n--)
{
scanf("%I64d%I64d",&a,&b);
ll h=w(1,1e6,a*b);
if(h==-1){printf("No\n");continue;}
//cout<<h<<endl;

if(a%h!=0||b%h!=0){printf("No\n");continue;}
//ll d1=a/h,d2=b/h;
//if(h%d1!=0||h%d2!=0){cout<<"No\n";continue;}
printf("Yes\n");



}
return 0;}