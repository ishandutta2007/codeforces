// Hydro submission #61db7b5b3aa9cfeed5852f98@1641773916056
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int ans[N],n;
void work(int l,int r){
    if(l>r)return;
    printf("? %d %d\n",l,r);
    fflush(stdout);
    int x,p;
    scanf("%d %d",&x,&p);
    int L=r-p+1,R=l+p-1;
    if(R>=L){
        for(int i=L;i<=R;i++)ans[i]=x;
        work(l,L-1),work(R+1,r);
    }
    else{
        int mid=l+r>>1;
        work(l,mid),work(mid+1,r);
    }
}
int main(){
    scanf("%d",&n);
    work(1,n);
    printf("! ");
    for(int i=1;i<=n;i++)printf("%d ",ans[i]);
}