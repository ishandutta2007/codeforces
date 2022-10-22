#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
int t,n,a[100];
cin>>t;
while(t--)
{
    cin>>n;
    int u=0;
    for(int i=0;i<n;i++){cin>>a[i];if(a[i]%2)u++;}
    if(u%2==0){cout<<"YES\n";continue;}
    sort(a,a+n);
bool bl=false;
   for(int i=1;i<n;i++)if(a[i]==a[i-1]+1)bl=true;
   if(bl)cout<<"YES\n";
   else cout<<"NO\n";
}

    return 0;
}