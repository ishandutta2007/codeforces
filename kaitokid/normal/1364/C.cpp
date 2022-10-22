#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[100009],b[100009];
int main()
{
    ios::sync_with_stdio(0);
int n;
cin>>n;
memset(b,-1,sizeof b);
queue<int>q;
for(int i=1;i<=n;i++)cin>>a[i];
for(int i=1;i<=n;i++)
{

    if(a[i]>a[i-1])b[i]=a[i-1];
    for(int j=a[i-1]+1;j<a[i];j++)q.push(j);

}

for(int i=1;i<=n;i++)
{
if(b[i]==-1){if(q.empty())b[i]=1000000;else{b[i]=q.front();q.pop();}}
if(!q.empty()&&q.front()<a[i]){cout<<-1;return 0;}
}
for(int i=1;i<=n;i++)cout<<b[i]<<" ";
       return 0;
}