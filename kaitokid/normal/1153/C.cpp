#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int n;
string s;
int main()
{
ios::sync_with_stdio(0);
cin>>n>>s;
if(n%2==1){cout<<":(";return 0;}
int l=0,r=0;
for(int i=0;i<n;i++){if(s[i]=='(')l++;if(s[i]==')')r++;}
l=n/2-l;
r=n/2-r;
if(l<0||r<0){cout<<":(";return 0;}
int d=0;
for(int i=0;i<n-1;i++)
{
if(s[i]=='?'){if(l>0){l--;s[i]='(';}
else {r--;s[i]=')';}}
if(s[i]=='(')d++;else d--;
if(d<=0){cout<<":(";return 0;}

}
s[n-1]=')';
cout<<s;
return 0;
}