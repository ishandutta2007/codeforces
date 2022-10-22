#include <bits/stdc++.h>
 using namespace std; 
typedef long long ll;
 int n; string s;
 int a[1000009];
 bool bl=false; 
int main()
 { ios::sync_with_stdio(0); 
cin>>n>>s; 
if(n%2==1){cout<<0;return 0;} 
if(s[0]==')')a[0]=-1;else a[0]=1; 
for(int i=1;i<n;i++) { if(s[i]==')')a[i]=a[i-1]-1;else a[i]=a[i-1]+1; if(a[i]<0)bl=true; 
if(a[0]<0)bl=true;
if(a[i]<-2){cout<<0;return 0;} } 
if(a[n-1]!=2&&a[n-1]!=-2){cout<<0;return 0;}
 if(a[n-1]==-2) { int ans=0; for(int i=0;i<n;i++){if(s[i]==')')ans++;if(a[i]<0)break;} cout<<ans; return 0; } if(bl){cout<<0;return 0;} int ans=0; for(int i=n-1;i>=0;i--) {if(a[i]<2)break; if(s[i]=='(')ans++;} cout<<ans; return 0; }