#include <cstdio>

long long gcd(long long a,long long b){
    if(!b)return a;
    return gcd(b,a%b);
}
long long se[4000001],n,q;
void build(int root,int l,int r){
    if(l==r){
        scanf("%d",se+root);
        return;
    }
    build(root<<1,l,(l+r)>>1);
    build(root<<1|1,((l+r)>>1)+1,r);
    se[root]=gcd(se[root<<1],se[root<<1|1]);
}
int query2(int root,int l,int r,int x){
    if(se[root]%x==0)return 0;
    if(l==r)return 1;
    if(se[root<<1]%x&&se[root<<1|1]%x)return 2;
    if(se[root<<1]%x)return query2(root<<1,l,(l+r)>>1,x);
    else return query2(root<<1|1,((l+r)>>1)+1,r,x);
}
int query(int root,int l,int r,int el,int er,int x){
    if(el>r||er<l)return 0;
    if(el<=l&&er>=r)return query2(root,l,r,x);
    return query(root<<1,l,(l+r)>>1,el,er,x)+query(root<<1|1,((l+r)>>1)+1,r,el,er,x);
}
void update(int root,int l,int r,int e,int x){
    if(l==r){
        se[root]=x;
        return;
    }
    if((l+r)>>1>=e)update(root<<1,l,(l+r)>>1,e,x);
    else update(root<<1|1,((l+r)>>1)+1,r,e,x);
    se[root]=gcd(se[root<<1],se[root<<1|1]);
}
int main(){
    scanf("%d",&n);
    build(1,1,n);
    scanf("%d",&q);
    int opt,l,r,x;
    for(int i=1;i<=q;i++){
        scanf("%d",&opt);
        if(opt==1){
            scanf("%d%d%d",&l,&r,&x);
            if(query(1,1,n,l,r,x)<=1)puts("YES");
            else puts("NO");
        }
        else{
            scanf("%d%d",&l,&x);
            update(1,1,n,l,x);
        }
    }
}