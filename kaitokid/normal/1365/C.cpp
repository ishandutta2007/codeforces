#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[200009],b[200009],ans[200009];
int n;
int main()
{
ios::sync_with_stdio(0);
cin>>n;
int x;
for(int i=0;i<n;i++){cin>>x;a[x]=i;}
for(int i=0;i<n;i++){cin>>x;b[x]=i;}
//for(int i=0;i<n;i++)ans[i]=n*2;
for(int i=1;i<=n;i++)
{
    int u=a[i]-b[i];
    if(u<0)u+=n;
    ans[u]++;
}
int an=0;
for(int i=0;i<n;i++)an=max(an,ans[i]);
cout<<an;
    return 0;
}