#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second
const int s=1e6;
int n,i,b,c,d,x,del,cnt1,cnt2,max1,max2,a[100001],dead[100001];
int my_pow(int x,int y)
{   int num=1;
    for(int i=x;y>0;i*=i,y>>=1)
        if(y&1)num*=i;
    return num;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>max1)max2=max1,max1=a[i],dead[max1]--;
        else if(a[i]>max2)dead[max1]++,max2=a[i];
    }
    del=1;
    for(int i=1;i<=n;i++) if(dead[i]>dead[del])del=i;

  cout<<del;
    return 0;
}