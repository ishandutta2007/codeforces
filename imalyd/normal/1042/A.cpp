//Problem A
#include<bits/stdc++.h>
using namespace std;
const int N=107;
int n,m,sum,mx;

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int a;scanf("%d",&a);
        sum+=a;mx=max(mx,a);
    }
    printf("%d %d",max(mx,(sum+m+n-1)/n),mx+m);
    return 0;
}