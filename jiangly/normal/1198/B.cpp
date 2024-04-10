#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
int t[N],a[N];
int v[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    scanf("%d",&q);
    for(int i=1;i<=q;++i){
        int op,x,y;
        scanf("%d",&op);
        switch(op){
            case 1:
                scanf("%d%d",&x,&y);
                t[x]=i;
                a[x]=y;
                break;
            case 2:
                scanf("%d",&x);
                v[i]=x;
                break;
        }
    }
    for(int i=q-1;i>=1;--i){
        v[i]=max(v[i],v[i+1]);
    }
    for(int i=1;i<=n;++i){
        printf("%d ",max(a[i],v[t[i]+1]));
    }
    return 0;
}