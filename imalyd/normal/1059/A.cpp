//Problem A
#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,a,l[N],r[N],s;

int main(){
    scanf("%d",&n);scanf("%d%d",&r[n],&a);
    for(int i=1;i<=n;i++)scanf("%d%d",&r[i-1],&l[i]),l[i]+=r[i-1];
    for(int i=0;i<=n;i++)s+=(r[i]-l[i])/a;
    printf("%d",s);
    return 0;
}