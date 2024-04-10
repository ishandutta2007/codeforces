#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n,cnt[10009];
vector<int>v;
int main()
{
ios::sync_with_stdio(0);
cin>>t;
while(t--)
{
v.clear();
bool bl=true;
int x;
for(int i=0;i<10009;i++)cnt[i]=0;
cin>>n;
for(int i=0;i<4*n;i++){cin>>x;cnt[x]++;}
for(int i=1;i<10009;i++)
{
if(cnt[i]%2==1){cout<<"NO\n";bl=false;break;}
for(int j=0;j<cnt[i]/2;j++)v.push_back(i);

}
if(bl==false)continue;
sort(v.begin(),v.end());
int r=v[0]*v[2*n-1];
for(int i=0;i<n;i++)
if(v[i]*v[2*n-1-i]!=r){cout<<"NO\n";bl=false;break;}
if(bl==false)continue;
cout<<"YES\n";
}
return 0;
}