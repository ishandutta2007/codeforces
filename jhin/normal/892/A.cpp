#include <bits/stdc++.h>

using namespace std;
long long n,sum;
long long a[100001],b[100001];
int main()
{
 cin>>n;
 for(int i=0;i<n;i++)cin>>a[i],sum+=a[i]; for(int i=0;i<n;i++)cin>>b[i];
sort(b,b+n);
if(sum<=b[n-1]+b[n-2])
cout<<"Yes";else cout<<"No";

    return 0;
}