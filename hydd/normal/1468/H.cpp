#include<bits/stdc++.h>
using namespace std;
int T,n,k,m,b[210000];
bool vis[210000];
bool work(){
    for (int i=1;i<=m;i++)
        if (b[i]-i>=(k-1)/2&&n-(m-i+1)+1-b[i]>=(k-1)/2) return true;
    return false;
}
int main(){
    scanf("%d",&T);
    while (T--){
        scanf("%d%d%d",&n,&k,&m);
        for (int i=1;i<=m;i++) scanf("%d",&b[i]);
        if ((n-m)%(k-1)==0&&work()) puts("YES");
        else puts("NO");
    }
    return 0;
}