#include <bits/stdc++.h>

using namespace std;
char a[1010],b[1010];
int n,m;
int changes(int pos){
    int ret=0;
    for(int i=pos; i<pos+n; i++){
        if(b[i]!=a[i-pos])ret++;
    }
    return ret;
}
int main() {
    scanf("%d %d",&n,&m);
    scanf("%s\n%s",a,b);
    int ans=1e9,pp=1e9;
    for(int i=0; i<=m-n; i++){
        if(changes(i)<ans){
            ans=changes(i);
            pp=i;
        }
    }
    printf("%d\n",ans);
    for(int i=pp; i<pp+n; i++){
        if(b[i]!=a[i-pp])printf("%d ",i-pp+1);
    }
    return 0;
}