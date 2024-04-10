#include<bits/stdc++.h>
using namespace std;
int a[110];
int main()
{
int t;
cin>>t;
while(t--)
{
int n,k;
cin>>n>>k;
for(int i=0;i<n;i++)
cin>>a[i];
if(k==1)
{
if(*max_element(a,a+n)==*min_element(a,a+n))
puts("1");
else puts("-1");
continue;
}
int M=0;
while(*max_element(a,a+n))
{
int last=-1;
int K=0;
for(int i=0;i<n;i++)
{
if(a[i]!=last&&K<k)
{
last=a[i];
K++;
}
a[i]-=last;
}
M++;
}
cout<<M<<endl;
}
return 0;;
}