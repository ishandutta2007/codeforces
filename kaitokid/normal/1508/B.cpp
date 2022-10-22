#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pw[100002];
int main()
{ios::sync_with_stdio(0);
pw[0]=1;
for(int i=1;i<63;i++)
    pw[i]=2*pw[i-1];
for(int i=63;i<=100000;i++)pw[i]=pw[i-1];
int t;
cin>>t;
while(t--)
{
    ll n,k;
    cin>>n>>k;
    if(k>pw[n-1]){cout<<-1<<endl;continue;}
    vector<int> v;
    v.push_back(0);
    for(int i=1;i<n;i++)
    {
        if(k<=pw[n-i-1])v.push_back(i);
        else k-=pw[n-i-1];

    }
v.push_back(n);
for(int i=1;i<v.size();i++)
    for(int j=v[i];j>v[i-1];j--)cout<<j<<" ";
cout<<endl;
}
    return 0;
}