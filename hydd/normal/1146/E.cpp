#include<bits/stdc++.h>
using namespace std;
int n,q,a[110000],num[110000],tree[110000];
void add(int x,int v){
    for (;x<=100000;x+=x&-x) tree[x]=max(tree[x],v);
}
int query(int x){
    if (!x) return 0;
    int res=0;
    for (;x;x-=x&-x) res=max(res,tree[x]);
    return res;
}
int main(){
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    char op[5]; int x,f=1;
    for (int i=1;i<=q;i++){
        scanf("%s%d",op,&x);
        if (f==-1){
            if (op[0]=='<') op[0]='>',x=-x;
            else op[0]='<',x=-x;
        }
        if (op[0]=='<'){
            if (x>0) f*=-1,x=x-1,op[0]='>';
        } else{
            if (x<0) f*=-1,x=x+1,op[0]='<';
        }
        if (op[0]=='<'){
            add(1-x,i);
            num[i]=1;
        } else{
            add(x+1,i);
            num[i]=-1;
        }
    }
    for (int i=1;i<=n;i++){
        int x=abs(a[i]),v=query(x);
        if (!v) printf("%d ",a[i]*f);
        else printf("%d ",x*num[v]*f);
    }
    return 0;
}