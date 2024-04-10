#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=3e5+10;
int k[mn];
int main()
{
    int n,i,sum=0;
    vector<int>v;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",k+i),sum+=k[i];
    v.push_back(0);
    for(i=1;i<n;i++)if(k[0]>=k[i]*2)v.push_back(i);
    int p=0;
    for(int x:v)p+=k[x];
    if(p>sum/2){
        printf("%d\n",v.size());
        for(int x:v)printf("%d ",x+1);
    }
    else printf("0");
}