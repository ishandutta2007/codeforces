// remote judge
#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int n;
int a[MAXN],b[MAXN];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;++i)
        scanf("%d",&b[i]);
    int x=0;
    for(int i=1;i<=n;++i)
        if(b[i]!=0)
            x=max(x,i-b[i]);
    bool flag=1;
    for(int i=1;i<=x;++i)
        if(b[i]!=0&&x-n+b[i]<=i)
            flag=0;
    for(int i=x+1;i<=n;++i)
        if(b[i]!=i-x)
            flag=0;
    if(flag){
        printf("%d\n",x);
        return 0;
    }
    x=n;
    for(int i=1;i<=n;++i)
        if(b[i]!=0)
            x=max(x,n+i-b[i]+1);
    printf("%d\n",x);
    return 0;
}