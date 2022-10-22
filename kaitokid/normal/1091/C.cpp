#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int mod=998244353;
set<int>v;
int main()
{
ios::sync_with_stdio(0);
ll n;
cin>>n;
ll d=n;
for(int i=1;i<100000;i++)
{
if(d%i==0){v.insert(i);v.insert(d/i);}

}

//cout<<v.size()<<endl;
set<int>::iterator it=v.end();
it--;
while(true)
{
ll ans=(2+n)*(n/(*it)+1)/2-n-1;
cout<<ans<<" ";
if(it==v.begin())break;
it--;}



return 0;
}