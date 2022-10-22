#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int num[409],n,x,d,ans=50000;
int main()
{
    ios::sync_with_stdio(0);
cin>>n>>d;
for(int i=0;i<n;i++){cin>>x;num[x]++;}
for(int i=1;i<300;i++)num[i]+=num[i-1];
for(int i=0;i<101;i++)ans=min(ans,n-(num[i+d]-num[i-1]));
cout<<ans;
return 0;
}