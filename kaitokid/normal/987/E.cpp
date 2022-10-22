#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int n, d,a[1000009];
bool vis[1000009];
int main()
{
ios::sync_with_stdio(0);
cin>>n;
for (int i=1;i<=n;i++)cin>>a[i];
for(int i=1;i<=n;i++)
{
if(vis[i])continue;
d++;
int j=i;
while(!vis[j]){vis[j]++;j=a[j];}

}
int ans=n-d;
if(ans%2==((3*n)%2)){cout<<"Petr";return 0;}
cout<<"Um_nik";
    return 0;
}