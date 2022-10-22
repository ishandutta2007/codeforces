#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
ll mn=100000000000,mx=-100000000000,sum=0,x;
int main()
{
    cin>>n;
for(int i=0;i<n;i++){cin>>x;sum+=abs(x);mn=min(mn,x);mx=max(mx,x);}
if(n==1)cout<<mn; else cout<<sum-abs(mn)-abs(mx)+mx-mn;

   return 0;
}