#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
string s;
ll n,k;
multiset<int>a;
ll po (ll a,ll b)
{
if(b==0)return 1;
if(b%2==1)return a*po(a,b-1);
ll m=po(a,b/2);
return m*m;


}
int main()
{
ios::sync_with_stdio(0);
cin>>n>>k;
ll m=n;
int j=0;
while(n!=0)
{
if(n%2==1)a.insert(j);
j++;
n/=2;

}

if(k<a.size()||k>m){cout<<"NO";return 0;}
cout<<"YES\n";
while(k>a.size())
{
int s=*(--a.end());
a.erase(--a.end());
a.insert(s-1);
a.insert(s-1);
}
multiset<int>::iterator it=a.begin();
while(it!=a.end())
{
ll k=po(2,(*it));
cout<<k<<" ";
it++;

}
    return 0;
}