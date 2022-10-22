#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
string s;
ll n;
int a[100009];
int main()
{
ios::sync_with_stdio(0);
cin>>n;
for(int i=0;i<n;i++)cin>>a[i];
sort(a,a+n);
ll ans1=a[n-2]-a[0];
ll ans2=a[n-1]-a[1];
cout<<min(ans1,ans2);
    return 0;
}