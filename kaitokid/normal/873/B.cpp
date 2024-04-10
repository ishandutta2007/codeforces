#include <bits/stdc++.h> 
using namespace std ;
int n,ans=0,v[200009],nu[2];
string s;
 int main(){
ios::sync_with_stdio(0);
memset(v,-1,sizeof v);

cin>>n>>s;
for(int i=0;i<n;i++)
{
nu[s[i]-'0']++;
if(nu[0]==nu[1]){ans=max(ans,i+1);continue;}
int q=nu[1]-nu[0]+100001;
if(v[q]==-1)v[q]=i;
ans=max(ans,i-v[q]);

}
cout<<ans;
return 0;}