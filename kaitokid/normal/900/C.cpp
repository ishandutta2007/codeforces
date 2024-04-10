#include <bits/stdc++.h>
using namespace std;
int x;
int vo=1000000;
int a[100009],b[100009];
int main()
{
ios::sync_with_stdio(0);

int n;
cin>>n;
int mi=0,ni=0,f=1000000,g=1000000;

for(int i=0;i<n;i++)
{
cin>>x;
 vo=min(x,vo);
if(i!=0&&x>mi&&x<ni){a[ni]++;}
if(i!=0&&x<ni)a[x]++;
//cout<<ni<<" "<<a[ni]<<endl;
if(x>ni){int l=ni;ni=x;mi=l;}
else{if(x>mi)mi=x;}

}
if(n==2){cout<<vo;return 0;}

int s=a[vo],ans=vo;
for(int i=vo+1;i<=100000;i++)
{if(a[i]>s){s=a[i];ans=i;}}
cout<<ans;
return 0;}