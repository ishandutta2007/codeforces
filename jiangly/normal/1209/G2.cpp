#include<bits/stdc++.h>
using namespace std;
const int MAX_N=200000;
int n,q;
int a[MAX_N];
set<int> pos[MAX_N];
int lmx[4*MAX_N];
int rmx[4*MAX_N];
int smx[4*MAX_N];
int mx[4*MAX_N];
int mn[4*MAX_N];
int lazy[4*MAX_N];
void pushDown(int p){
    mn[p<<1]+=lazy[p];
    lazy[p<<1]+=lazy[p];
    mn[p<<1|1]+=lazy[p];
    lazy[p<<1|1]+=lazy[p];
    lazy[p]=0;
}
void pushUp(int p){
    if(mn[p<<1]==mn[p<<1|1]){
        lmx[p]=lmx[p<<1];
        rmx[p]=rmx[p<<1|1];
        smx[p]=smx[p<<1]+smx[p<<1|1]+max(rmx[p<<1],lmx[p<<1|1]);
    }else if(mn[p<<1]<mn[p<<1|1]){
        lmx[p]=lmx[p<<1];
        rmx[p]=max(rmx[p<<1],mx[p<<1|1]);
        smx[p]=smx[p<<1];
    }else{
        lmx[p]=max(mx[p<<1],lmx[p<<1|1]);
        rmx[p]=rmx[p<<1|1];
        smx[p]=smx[p<<1|1];
    }
    mx[p]=max(mx[p<<1],mx[p<<1|1]);
    mn[p]=min(mn[p<<1],mn[p<<1|1]);
}
void modify(int p,int l,int r,int x,int y){
    if(r-l==1){
        rmx[p]=y;
        mx[p]=y;
        return;
    }
    int mid=(l+r)>>1;
    pushDown(p);
    if(x<mid){
        modify(p<<1,l,mid,x,y);
    }else{
        modify(p<<1|1,mid,r,x,y);
    }
    pushUp(p);
}
void rangeAdd(int p,int l,int r,int x,int y,int z){
    if(l>=y||r<=x){
        return;
    }
    if(l>=x&&r<=y){
        mn[p]+=z;
        lazy[p]+=z;
        return;
    }
    int mid=(l+r)>>1;
    pushDown(p);
    rangeAdd(p<<1,l,mid,x,y,z);
    rangeAdd(p<<1|1,mid,r,x,y,z);
    pushUp(p);
}
int main(){
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
        --a[i];
        pos[a[i]].insert(i);
    }
    for(int i=0;i<200000;++i){
        if(!pos[i].empty()){
            modify(1,0,n+1,*pos[i].begin(),pos[i].size());
            rangeAdd(1,0,n+1,*pos[i].begin()+1,*pos[i].rbegin()+1,1);
        }
    }
    printf("%d\n",n-smx[1]);
    for(int i=0;i<q;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        --x;
        --y;
        modify(1,0,n+1,*pos[a[x]].begin(),0);
        rangeAdd(1,0,n+1,*pos[a[x]].begin()+1,*pos[a[x]].rbegin()+1,-1);
        pos[a[x]].erase(x);
        if(!pos[a[x]].empty()){
            modify(1,0,n+1,*pos[a[x]].begin(),pos[a[x]].size());
            rangeAdd(1,0,n+1,*pos[a[x]].begin()+1,*pos[a[x]].rbegin()+1,1);
        }
        a[x]=y;
        if(!pos[y].empty()){
            modify(1,0,n+1,*pos[y].begin(),0);
            rangeAdd(1,0,n+1,*pos[y].begin()+1,*pos[y].rbegin()+1,-1);
        }
        pos[y].insert(x);
        modify(1,0,n+1,*pos[y].begin(),pos[y].size());
        rangeAdd(1,0,n+1,*pos[y].begin()+1,*pos[y].rbegin()+1,1);
        printf("%d\n",n-smx[1]);
    }
    return 0;
}