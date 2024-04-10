// luogu remote judge
#include<bits/stdc++.h>
template<class T>const T&min(const T&a,const T&b){
    if(a<b)
        return a;
    return b;
}
template<class T>const T&max(const T&a,const T&b){
    if(a>b)
        return a;
    return b;
}
template<class T>void swap(T&a,T&b){
    T c=a;
    a=b;
    b=c;
}
const int MAXN=300005,MAXM=MAXN*5;
int n,m;
int a[MAXN];
std::pair<int,int>q[MAXM];
void swap_id(int i,int j){
    q[++m]={i,j};
    swap(a[i],a[j]);
}
void rswap(int i,int j){
    if(i>j)
        swap(i,j);
    if(j-i>=n/2){
        swap_id(i,j);
    }else if(j<=n/2){
        swap_id(i,n);
        swap_id(j,n);
        swap_id(i,n);
    }else if(i>n/2){
        swap_id(i,1);
        swap_id(j,1);
        swap_id(i,1);
    }else{
        swap_id(1,j);
        swap_id(1,n);
        swap_id(i,n);
        swap_id(1,n);
        swap_id(1,j);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;++i)
        for(;a[i]!=i;rswap(i,a[i]));
    printf("%d\n",m);
    for(int i=1;i<=m;++i)
        printf("%d %d\n",q[i].first,q[i].second);
    return 0;
}