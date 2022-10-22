#include <bits/stdc++.h>

using namespace std;

int main()
{
 ios::sync_with_stdio(0);
 int a,b,c,d,k,t;
 cin>>t;
 while(t--)
 {
int n;
string s;
cin>>n>>s;
int ans=n;
for(int i=0;i<n;i++)
if(s[i]=='1'){ans=max(ans,2*(i+1));ans=max(ans,2*(n-i));ans=max(ans,n+1);}
 cout<<ans<<endl;
 }
    return 0;
}