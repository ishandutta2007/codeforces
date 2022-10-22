#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod=998244353;
int n,a[200],d,r[200];
bool bl;
int main()
{
ios::sync_with_stdio(0);
cin>>n;
for(int i=0;i<n;i++)
{
    cin>>a[i];
    r[a[i]]++;
    if(r[a[i]]==3)bl=true;
    if(r[a[i]]==2)d--;
    if(r[a[i]]==1)d++;

}
if(!bl&&(d%2==1)){cout<<"NO";return 0;}
cout<<"YES\n";
if(d%2==0)bl=false;
int u=0;
for(int i=0;i<n;i++)
{
    if(r[a[i]]==1){if(u==0)cout<<"A";else cout<<"B";u=(1+u)%2;continue;}
    if(r[a[i]]>2&&bl){cout<<"B";bl=false;continue;}
    cout<<"A";

}
 return 0;
}