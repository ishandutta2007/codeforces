#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k,n,w;
    scanf("%d%d%d",&k,&n,&w);
    for (int i=1;i<=w;i++) n-=i*k;
    if (n>=0) printf("0");
    else printf("%d",-n);
    return 0;
}