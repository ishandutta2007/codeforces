#include<bits/stdc++.h>
using namespace std;
const int mn=1e6+10;
int num[mn];
int main(){
    int n,m,dx,dy;
    scanf("%d%d%d%d",&n,&m,&dx,&dy);
    int idx,i;
    for(i=1;i<n;i++)if(1LL*dx*i%n==1)idx=i;
    for(i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        b=b-1LL*a*idx%n*dy%n;
        b%=n;
        if(b<0)b+=n;
        num[b]++;
    }
    int bes=0;
    for(i=1;i<n;i++)if(num[i]>num[bes])bes=i;
    printf("0 %d",bes);
}