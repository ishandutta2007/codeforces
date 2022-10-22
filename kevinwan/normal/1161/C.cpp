#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=2e5+10;
const int inf=0x3f3f3f3f;
int k[mn];
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",k+i);
    sort(k,k+n);
    int num=0;
    for(i=0;i<n;i++)if(k[0]==k[i])num++;
    if(num>n/2)printf("Bob");
    else printf("Alice");
}