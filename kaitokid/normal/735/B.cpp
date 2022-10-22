#include<bits/stdc++.h>
using namespace std;
int a[100009];
int main()
{
int n,n1,n2;
double ans1=0,ans2=0;
cin>>n>>n1>>n2;
for(int i=0;i<n;i++)cin>>a[i];
sort(a,a+n);
for(int i=n-1;i>=n-min(n1,n2);i--)ans1+=a[i];
ans1/=min(n1,n2);
//cout<<ans1;
for(int i=n-min(n1,n2)-1;i>=n-min(n1,n2)-max(n1,n2);i--)ans2+=a[i];
//cout<<" " <<ans2<<endl;
ans2/=max(n1,n2);
//cout<<" " <<ans2<<endl;
printf("%.6lf",ans1+ans2);
//cout<<fixed(6)<<ans1+ans2;
 return 0;
}