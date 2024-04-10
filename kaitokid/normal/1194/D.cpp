#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,k;

int main()
{
ios::sync_with_stdio(0);
cin>>t;
for(int i=0;i<t;i++)
{
cin>>n>>k;
if(k%3!=0){if(n%3==0)cout<<"Bob\n";else cout<<"Alice\n";continue;} 
if(n%(k+1)==k){cout<<"Alice\n";continue;}
if((n%(k+1)%3)==0){cout<<"Bob\n";continue;}
cout<<"Alice\n";
}
return 0;
}