#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
vector<ll> a[2];
ll d[200009][3];
ll mod=998244353;
ll n,k,x;
int main()
{
ios::sync_with_stdio(0);

cin>>n>>k;
d[1][0]=k-1;
d[1][1]=0;
d[1][2]=1;
for(int i=2;i<200005;i++)
{d[i][0]=d[i-1][0]*(k-1);
d[i][0]%=mod;
d[i][1]=(d[i-1][0]-d[i-1][1]+mod)%mod;
d[i][2]=(d[i-1][0]-d[i-1][2]+mod)%mod;

}

for(int i=0;i<n;i++)
{
cin>>x;
if(x==-1&&i>1&&a[i%2][a[i%2].size()-1]<0)a[i%2][a[i%2].size()-1]--;
else 
a[i%2].push_back(x);}
ll ans=1;
for(int i=0;i<2;i++){
if(a[i].size()==1&&a[i][0]<0){
ans*=k;
for(int j=1;j<-1*a[i][0];j++){ans*=(k-1);ans%=mod;}
continue;}
if(a[i][0]<0)
for(int j=0;j<-a[i][0];j++){ans*=(k-1);ans%=mod;}
if(a[i][a[i].size()-1]<0)
for(int j=0;j<-a[i][a[i].size()-1];j++){ans*=(k-1);ans%=mod;}
for(int j=1;j<a[i].size()-1;j++)
{
if(a[i][j]==a[i][j-1]||a[i][j]==a[i][j+1]){cout<<0;return 0;}

if(a[i][j]<0){
ll q=-1*a[i][j];
if(a[i][j-1]==a[i][j+1]){
ans*=d[q+1][1];ans%=mod;

}
else {ans*=d[q+1][2];ans%=mod;}
}
}

}
cout<<ans;
return 0;
}