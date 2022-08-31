#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<functional>
using namespace std;
int n,k;
int a[2005];
int b[2005]={0};
int ans=0;
int main()
{
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++)scanf("%d",&a[i]),b[a[i]]++;
 /*   sort(a+1,a+1+n,greater<int>());
    for (int i=1;i<=n;i+=k)ans+=a[i];
    printf("%d\n",ans*2);
    return 0;*/
    for (int i=1999;i>=2;i--)b[i]+=b[i+1];
    for (int i=2000;i>=2;i--)ans+=(b[i]+k-1)/k;
    printf("%d\n",ans*2);
    return 0;
}