#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[101];
int main()
{
    ios::sync_with_stdio(0);
int t;
cin>>t;
while(t--)
{int n;
cin>>n;
for(int i=0;i<=100;i++)a[i]=0;
for(int i=0;i<n;i++)
{
    int x;
    cin>>x;
    a[x]++;
}
int u=1000,v=1000;
for(int i=0;i<102;i++)
{
    if(a[i]>=2)continue;
    if(a[i]==1){u=min(u,i);continue;}
    v=min(v,i);
    u=min(u,i);
}
cout<<u+v<<endl;

}
}