#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q,a[200009],when[200009],lst[200009];
int typ,x,p;
int main()
{
ios::sync_with_stdio(0);
cin>>n;
for(int i=0;i<n;i++)cin>>a[i];
cin>> q;
for(int i=0;i<q;i++)
{
cin>>typ;
if(typ==1)
{
cin>>p>>x;
p--;
a[p]=x;
when[p]=i;
continue;


}

cin>>x;
lst[i]=x;

}
for(int i=q-1;i>=0;i--)
lst[i]=max(lst[i],lst[i+1]);
for(int i=0;i<n;i++)cout<<max(a[i],lst[when[i]])<<" ";
return 0;}