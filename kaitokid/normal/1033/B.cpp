#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
bool pr[1000009];
vector<ll>p;
int main()
{
for(int i=2;i<=1009;i++)
{
if(pr[i])continue;
for(int j=i*i;j<1000009;j+=i)
pr[j]=true;

}
for(int i=2;i<1000009;i++)if(!pr[i])p.push_back(i);

    int t;
ll a,b;
cin>>t;
while(t--)
{

cin>>a>>b;

if(a!=b+1) {cout<<"NO\n";continue;}
bool bl=false;
for(int q=0;q<p.size();q++)
{if(p[q]>=a+b)break;
if((a+b)%p[q]==0){cout<<"NO\n";bl=true;break;}}
if(!bl)cout<<"YES\n";
}
    return 0;
}