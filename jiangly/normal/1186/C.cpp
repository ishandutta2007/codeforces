// luogu remote judge
#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
char a[N],b[N];
int sum[N];
int main(){
    scanf("%s%s",a+1,b+1);
    int n=strlen(a+1);
    int m=strlen(b+1);
    int s=0;
    for(int i=1;i<=m;++i){
        s^=(b[i]-'0');
    }
    for(int i=1;i<=n;++i){
        sum[i]=sum[i-1]^(a[i]-'0');
    }
    int ans=0;
    for(int i=m;i<=n;++i){
        ans+=((sum[i]^sum[i-m])==s);
    }
    printf("%d\n",ans);
    return 0;
}