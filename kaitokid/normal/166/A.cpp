#include <bits/stdc++.h>

using namespace std;
bool v(pair<int ,int>a,pair<int,int>b)
{
    if(a.first>b.first||(a.first==b.first&&a.second<b.second)){return true;}
    return false;
}
pair<int,int> f[60];
int main()
{
int n,k,x,y;
cin>>n>>k;
for(int i=0;i<n;i++)
{
    cin>>x>>y;
    f[i].first=x;
    f[i].second=y;
}

sort (f,f+n,v);
k--;
int l=1;
int i=k-1;
while(f[i]==f[k]&&i>=0){l++;i--;}
i=k+1;
while(f[i]==f[k]&&i<=n){l++;i++;}
cout<<l;
    return 0;
}