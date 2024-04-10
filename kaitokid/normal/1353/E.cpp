#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll t,n,k,u,ans;
string s;
ll go(string x)
{
ll m=x.size();
ll d=0;
for(int i=0;i<m;i++)
    if(x[i]=='1')d++;
    ll res=d;
ll l=0,r=0,u=0;
if(x[0]=='1')u=1;
while(l<m)
{
    if(r<l){r=l;if(x[l]=='1')u=1;else u=0;}

    res=min(res,d-u+r-l+1-u);
    if(r-l+1-u>u){if(x[l]=='1')u--;l++;continue;}
    r++;
    if(r>m-1)break;
    if(x[r]=='1')u++;

}
return res;}
int main()
{ios::sync_with_stdio(0);
cin>>t;

while(t--)
{
    cin>>n>>k>>s;
u=0;

for(int i=0;i<n;i++)if(s[i]=='1')u++;
ans=u;
for(int i=0;i<k;i++)
{
    string v;
    ll d=0;
    for(int j=i;j<n;j+=k){v+=s[j];if(s[j]=='1')d++;}

    ans=min(ans,u-d+go(v));
}
cout<<ans<<endl;
}
    return 0;
}