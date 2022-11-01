#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int ans=n*2/k+(n*2%k?1:0)+n*5/k+(n*5%k?1:0)+n*8/k+(n*8%k?1:0);
    printf("%d\n",ans);
}