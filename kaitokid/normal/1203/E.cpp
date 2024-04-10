#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a[150009],ans;
bool bl[150009];
int main()
{
ios::sync_with_stdio(0);
cin>>n;
for(int i=0;i<n;i++)
cin>>a[i];
sort(a,a+n);
for(int i=0;i<n;i++)
{
if(a[i]>1&&bl[a[i]-1]==false){bl[a[i]-1]=true;ans++;continue;}
if(bl[a[i]]==false){bl[a[i]]=true;ans++;continue;}
if(bl[a[i]+1]==false){bl[a[i]+1]=true;ans++;continue;}

}
cout<<ans;
return 0;}