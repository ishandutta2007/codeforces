#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
bool bl[3000009];
int main()
{
ios::sync_with_stdio(0);
int t,n,k;
string s;
cin>>t;

    vector<pair<int,int> >ans;
while(t--)
{
    cin>>n>>k;
    cin>>s;
    int r=n-k+3;
    if(k<22)r=min(r,(1<<k)-1);
    int u=min(20,k);
    int y=(1<<u)-1;
    for(int i=0;i<=r;i++)bl[i]=false;
int i=0,j=k-u,d=k-1,gg=0,h=0;
for(int f=0;f<j;f++)if(s[f]=='1')h++;
for(int f=j;f<=d;f++)gg=(gg*2+(s[f]-'0'));
if(h==k-u)bl[gg^y]=true;
while(d+1<n)
{
 if(s[i]=='1')h--;
 if(s[j]=='1'){h++;gg-=(1<<(u-1));}
 i++;
 j++;
 d++;
    gg=(gg*2+(s[d]-'0'));
if(h==k-u)bl[gg^y]=true;
}
int ans=-1;
for(int i=0;i<=r;i++)
if(!bl[i]){ans=i;break;}
if(ans==-1){cout<<"NO\n";continue;}
cout<<"YES\n";
for(int i=0;i<k-u;i++)cout<<"0";
for(int i=u-1;i>=0;i--)if((1<<i)&ans)cout<<"1";else cout<<"0";
cout<<endl;

}
    return 0;
}