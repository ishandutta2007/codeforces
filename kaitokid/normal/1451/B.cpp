#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
bool pr[209],suf[209];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int t,n;
cin>>t;
while(t--)
{string s;
int n,q;
cin>>n>>q>>s;

int fr0=-1,fr1=-1,en0=-1,en1=-1;
for(int i=0;i<s.size();i++)
if(s[i]=='0'){fr0=i;break;}
for(int i=0;i<s.size();i++)
if(s[i]=='1'){fr1=i;break;}
for(int i=s.size()-1;i>0;i--)
if(s[i]=='0'){en0=i;break;}
for(int i=s.size()-1;i>0;i--)
if(s[i]=='1'){en1=i;break;}
int l,r;
while(q--)
{
    cin>>l>>r;
    l--,r--;
    int u=0;
    if(l==fr0||l==fr1)u++;
    if(r==en0||r==en1)u++;
    if(u==2)cout<<"NO\n";
    else cout<<"YES\n";

}
}
    return 0;
}