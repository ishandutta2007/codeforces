#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
int MOD=1e9 +7;
vector<int> v;
int a[1009];
int p[1009][1009];
string s;
long long ans=0;
void go(int i)
{

ans+=p[s.size()][i];

ans=ans%MOD;
for(int j=0;j<v.size();j++)
{
if(i<=v[j]-j)break;
//cout<<i<<endl;
ans-=p[s.size()-v[j]-1][i-v[j]+j-1];
if(ans<0)ans+=MOD;

}


}
int main() {
ios::sync_with_stdio(0);
for(int i=0;i<1001;i++)
p[i][0]=1;
for(int i=1;i<1001;i++)
{
for(int j=1;j<i;j++)
{p[i][j]=p[i-1][j]+p[i-1][j-1];p[i][j]=p[i][j]%MOD;}
p[i][i]=1;



}
//cout<<p[3][2]<<endl;

cin>>s;
int k;
cin>>k;
for(int i=0;i<s.size();i++)
if(s[i]=='0')v.push_back(i);
if(k==0){cout<<1;return 0;}
if(k==1){go(1);ans--;}
for(int i=2;i<1001;i++)
{
int x=i,v=0;
while(x!=0)
{
if(x%2)v++;
x/=2;


}
a[i]=a[v]+1;

if(a[i]==k-1){go(i);}



}
cout<<ans;
 return 0; }