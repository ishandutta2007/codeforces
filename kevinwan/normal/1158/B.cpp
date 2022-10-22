#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=1e5+10;
int main()
{
    int n,k,i;
    scanf("%d%d",&n,&k);
    int l=(n-k)/2+1;
    for(i=1;i<=n;i++){
        if(i%l)printf("0");
        else printf("1");
    }
}