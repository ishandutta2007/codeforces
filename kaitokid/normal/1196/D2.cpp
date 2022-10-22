#include<bits/stdc++.h>
using namespace std;
int q,n,k;
string s;
string a[3];
int main()
{
ios::sync_with_stdio(0);
a[0]="RGB";
a[1]="GBR";
a[2]="BRG";
cin>>q;
while(q--)
{
cin>>n>>k>>s;
int ans=200009;
for(int j=0;j<3;j++)
{
int res=0;
for(int i=0;i<k;i++)
if(s[i]!=a[j][i%3])res++;
ans=min(ans,res);
int i=0,d=k;
while(d<n)
{
if(s[i]!=a[j][i%3])res--;
if(s[d]!=a[j][d%3])res++;
ans=min(ans,res);
i++;
d++;
}
}
cout<<ans<<endl;

}



return 0;}